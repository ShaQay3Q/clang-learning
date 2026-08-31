#include "helpers.h"
#include <math.h>
#include <stdlib.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avrage = round(((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0));
            image[i][j].rgbtBlue = avrage;
            image[i][j].rgbtGreen = avrage;
            image[i][j].rgbtRed = avrage;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE pixel;
            pixel = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = pixel;            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel;

            int sum_b = 0;
            int sum_g = 0;
            int sum_r = 0;
            int count = 0;

            // di/dj = movement
            // i + di / j + dj = actual neighbor coordinate
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (0 <= i + di && i + di < height)
                    {
                        if (0 <= j + dj && j + dj < width)
                        {
                            sum_b = sum_b + image[i + di][j + dj].rgbtBlue;
                            sum_g = sum_g + image[i + di][j + dj].rgbtGreen;
                            sum_r = sum_r + image[i + di][j + dj].rgbtRed;

                            count++;
                        }
                    }
                }
            }

            pixel.rgbtBlue = round((float)sum_b / count);
            pixel.rgbtGreen = round((float)sum_g / count);
            pixel.rgbtRed = round((float)sum_r / count);

            copy[i][j] = pixel;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int X[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE px;

            int s_red[2] = {0, 0};
            int s_green[2] = {0, 0};
            int s_blue[2] = {0, 0};

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (0 <= i + di && i + di < height)
                    {
                        if (0 <= j + dj && j + dj < width)
                        {
                            s_blue[0] = (s_blue[0] + image[i + di][j + dj].rgbtBlue * X[di+1][dj+1]);
                            s_blue[1] = (s_blue[1] + image[i + di][j + dj].rgbtBlue * Y[di+1][dj+1]);
                            s_green[0] = (s_green[0] + image[i + di][j + dj].rgbtGreen * X[di+1][dj+1]);
                            s_green[1] = (s_green[1] + image[i + di][j + dj].rgbtGreen * Y[di+1][dj+1]);
                            s_red[0] = (s_red[0] + image[i + di][j + dj].rgbtRed * X[di+1][dj+1]);
                            s_red[1] = (s_red[1] + image[i + di][j + dj].rgbtRed * Y[di+1][dj+1]);

                        }
                    }
                }
            }

            int blue = round(sqrt((s_blue[0] * s_blue[0]) + s_blue[1] * s_blue[1]));
            int green = round(sqrt((s_green[0] * s_green[0]) + s_green[1] * s_green[1]));
            int red = round(sqrt((s_red[0] * s_red[0]) + s_red[1] * s_red[1]));

            px.rgbtBlue = blue > 255 ? 255 : blue;
            px.rgbtGreen = green > 255 ? 255 : green;
            px.rgbtRed = red > 255 ? 255 : red;

            copy[i][j] = px;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

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
    return;
}

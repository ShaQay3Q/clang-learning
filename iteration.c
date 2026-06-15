#include "./src/cs50.h"
#include <stdio.h>

void draw_pyramid(int n);

int main(void)
{
    int height = get_int("Hight of the pyramid: ");

    draw_pyramid(height);
}

void draw_pyramid(int n)
{
    // For each row of pyramid
    for (int i = 0; i < n; i++)
    {
        // For each column of pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
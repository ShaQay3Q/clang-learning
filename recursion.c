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
    if (n <= 0)
        return;     
    draw_pyramid(n - 1);
    for (int i = 0; i < n; i++)
        printf("#");
    printf("\n");
}
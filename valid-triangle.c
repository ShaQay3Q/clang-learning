#include "./src/cs50.h"
#include <stdbool.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);


int main(void)
{
    int a = get_int("First side length: \n");
    int b = get_int("Socond side length: '\n");
    int c = get_int("Third side length: '\n");

    if (a < 1 || b < 1 || c < 1)
    {
        printf("No valid measurements were given.\n");
        return 1;
    }

    if (valid_triangle(a, b, c))
    {
        printf("These measurements form a triangle.\n");
    }
    else
    {
        printf("Given measure don't indicate to a triangle.");
    }
    return 0;
}

bool valid_triangle(int a, int b, int c)
{
    return (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}


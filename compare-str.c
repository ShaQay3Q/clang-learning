#include "./src/cs50.h"
#include <stdio.h>

int main(void)
{
    int j = 50;
    int i = 60;

    if ( i == j)
        printf("%i = %i\n", i, j);
    else if (i < j)
        printf("%i < %i\n", i, j);
    else
        printf("%i > %i\n", i, j);
}
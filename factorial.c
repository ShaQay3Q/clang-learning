#include <stdio.h>
#include "./src/cs50.h"


int factorial(int n);

int main(void)
{
    int n = 3;
    int output = factorial(n);
    printf("result: %i\n", output);
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return (n * factorial(n - 1 ));
}
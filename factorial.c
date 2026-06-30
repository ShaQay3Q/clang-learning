#include <stdio.h>
#include "./src/cs50.h"


int factorial(int n);

int main(void)
{
    int n = get_int("Enter a number: ");
    int output = factorial(n);
    printf("result: %i\n", output);
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return (n * factorial(n - 1 ));
}
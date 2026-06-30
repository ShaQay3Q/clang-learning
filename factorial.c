#include <stdio.h>
#include "./src/cs50.h"


int factorial(int n);

int main(void)
{
    int n = get_int("factorial of: ");
    printf("is: %i\n", factorial(n));
}

int factorial(int n)
{
    if (n < 0)
        return -1;

    if (n == 0)
        return 1;

    return (n * factorial(n - 1 ));
}
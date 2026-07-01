#include "./src/cs50.h"
#include <limits.h>
#include <stdio.h>

int fbncc_sqnc(int n);


int main(void)
{
    int n = get_int("Fibonacci sequence of: ");

    if (n < 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("is: %i\n", fbncc_sqnc(n));

}

//! Fibonacci Sequence is a a TREE RECURSION
//! wherase the Factorial is a lINEAR RECURSION
int fbncc_sqnc(int n)
{
    // Base case
    if (n <= 1) return n;

    // Recursive case
    return fbncc_sqnc(n - 1) + fbncc_sqnc(n - 2);
}
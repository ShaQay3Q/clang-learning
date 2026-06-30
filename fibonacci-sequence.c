#include "./src/cs50.h"
#include <stdio.h>

int fbncc_sqnc(int n);


int main(void)
{
    int n = get_int("Fibonacci sequence of: ");

    printf("is: %i\n", fbncc_sqnc(n));

}

//! Fibonacci Sequence is a a TREE RECURSION
//! wherase the Factorial is a lINEAR RECURSION
int fbncc_sqnc(int n)
{
    // Error case
    if (n < 0)
        return -1;
    // Base case
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // Recursive case
    return fbncc_sqnc(n - 1) + fbncc_sqnc(n - 2);
}
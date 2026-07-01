#include "./src/cs50.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool fbncc_sqnc(int n, int *result);


int main(void)
{
    int result;

    if (!fbncc_sqnc(get_int("Fibonacci sequence of: "), &result))
    {
        printf("Invalid input\n");
        return 1;
    }

    printf("is: %i\n", result);
    return 0;

}

//! Fibonacci Sequence is a a TREE RECURSION
//! wherase the Factorial is a lINEAR RECURSION
bool fbncc_sqnc(int n, int *result)
{   
    // Invalid case
    if (n < 0) return false;

    // Base case
    if (n <= 1)
    {
        *result = n;
        return true;
    }

    // recursive part
    int a;
    int b;

    if (!fbncc_sqnc(n-1, &a)) return false;
    
    if (!fbncc_sqnc(n-2, &b)) return false;
    
    *result = a + b;
    return true;
}

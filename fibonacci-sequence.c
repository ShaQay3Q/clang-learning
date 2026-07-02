#include "./src/cs50.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool fbncc_sqnc(int n, int *result);
int fibonacci(int x);
int fib(int prev, int curr, int steps);


int main(void)
{
    int n = get_int("Fibonacci number: ");
    // int result;

    // if (!fbncc_sqnc(n, &result))
    // {
    //     printf("Invalid input\n");
    //     return 1;
    // }

    // printf("is: %i\n", result);
    printf("Fibonnaci number of %i, is %i\n", n, fibonacci(n));

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
    int a, b;

    fbncc_sqnc(n-1, &a);
    fbncc_sqnc(n-2, &b);
    
    *result = a + b ;
    return true;
}

// Wrapper function
int fibonacci(int x)
{
    if (x == 0)
        return x;
    return fib(0, 1, x-1);
}

// Recursive function
int fib(int prev, int curr, int steps)
{
    if (steps == 0)
        return curr;

    return fib(curr, prev + curr, steps - 1);
}
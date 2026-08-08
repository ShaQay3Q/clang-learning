#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // give me the address if n
    // printf("%i\n", n);
    printf("%p\n", p);
    // printf("%p\n", &n); // %p => is for pointer
    printf("%i\n", *p); //! Dereference operator
}
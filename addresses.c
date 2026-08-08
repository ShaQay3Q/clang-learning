#include "./src/cs50.h"
#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    // int n = 50;
    // int *p = &n; // give me the address if n
    // printf("%i\n", n);
    // printf("%p\n", p);
    // printf("%p\n", &n); // %p => is for pointer
    // printf("%i\n", *p); //! Dereference operator

    string s = "HI!";
    printf("%s\n", s);
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

}
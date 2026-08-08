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

    char *s = "HI!";
    printf("%s\n", s);
    printf("%p\n", &s);

    printf("%c\n", *s); // => s[0]
    printf("%c\n", *(s+1)); // => s[1]
    printf("%c\n", *(s+2)); // => s[2]


    printf("%c\n", s[1]);
    printf("%c\n", s[2]);


}
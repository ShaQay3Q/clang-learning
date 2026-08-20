#include "./src/cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = s; // t is the copy of the address of the string which s holds

    // printf("s is %s\n", s);
    printf("s is %s\n", s);
    printf("t is %s\n", t);

    printf("S[0]: %c\n", *s);
    printf("S[0]: %c\n", *(s + 1)); // Doing arritmatic on pointer
    printf("S[0]: %c\n", *(s + 2)); // The next address is one digit away!

    printf("%p: \n", &s);
    printf("%p: \n", &t);

    t[0] = toupper(*t);
    printf("t: %s\n", t);
    printf("s: %s\n", s);

}
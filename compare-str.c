#include "./src/cs50.h"
#include <stdio.h>
#include <string.h>


int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if ( strcmp(s,t) == 0) // compares two strings together
        printf("Same\n");
    else
        printf("Different\n");

    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n", &s[4]);
    printf("%c\n", s[4]);

    printf("%p\n", t);

}
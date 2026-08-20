#include "./src/cs50.h"
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    int l = strlen(s);

    printf("l: %i\n", l);
    char *t = malloc((l + 1)); // length s + extra bite for \0 char (null terminator) //! NUL charachter
    //OR
    // char *t = malloc((l + 1) * sizeof(char)) //! sizeof(char) is always 1
    // strcpy() make a copy of a string
    strcpy(t, s);

    t[0] = toupper(*t);
    printf("s is %s\n", s);
    printf("t is %s\n", t);
}
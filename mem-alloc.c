#include "./src/cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    int l = strlen(s);

    printf("l: %i\n", l);
    char *t = malloc(l + 1); // length s + extra bite for \0 char
    // printf("s is %s\n", s);
    for (int i =0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(*t);
    printf("s is %s\n", s);
    printf("t is %s\n", t);
}
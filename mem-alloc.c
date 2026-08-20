#include "./src/cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(4);
    // printf("s is %s\n", s);
    printf("s is %s\n", s);
    printf("t is %p\n", t);
}
#include <stdio.h>


int main(void)
{
    printf("Enter a character: ");
    char c = fgetc(stdin);
    fprintf(stdout, "%c\n", c);
    return 0;
}
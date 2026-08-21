#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s;
    s = malloc(8*sizeof(char));

    if (s == NULL) return 1;

    printf("s: ");
    scanf("%s", s);
    printf("%s\n", s);

    free(s);
    return 0;
}
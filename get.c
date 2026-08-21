#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *n;
    n = malloc(8*sizeof(int));
    if (n == NULL)
    {
        return 1;
    }
    printf("n: ");
    scanf("%i", n);
    printf("n: %i\n", *n);
    free(n);
    return 0;
}
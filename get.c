#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    // n = malloc(sizeof(int));
    // if (n == NULL)
    // {
    //     return 1;
    // }
    printf("n: ");
    scanf("%i", &n); // gets the address of n and assign the value to it
    printf("n: %i\n", n);
    // free(n);
    return 0;
}
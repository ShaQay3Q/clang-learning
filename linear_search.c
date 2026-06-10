#include "./src/cs50.h"
#include <stdio.h>

int main(void)
{
    int n = get_int("Search for number: ");
    int numbers[] = {1, 4, 3, 6, 9, 10, 12, 5, 7, 8, 2, 11};
    int length = (int)sizeof(numbers)/4; // sizeof() -> runtime -> gives the size in bytes ==> /4 is needed
    for(int i = 0; i < length-1; i++)
    {
        if (numbers[i] == n)
        {
            printf("array[%d] has the value of %d\n", i, n);
            return 0;
        }
    }
    printf("%i was not found!\n", n);
    return 1;
}
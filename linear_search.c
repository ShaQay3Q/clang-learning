#include "./src/cs50.h"
#include <stdio.h>

int main(void)
{
    int array[] = {1, 4, 3, 6, 9, 10, 12, 5, 7, 8, 2, 11};
    int length = (int)sizeof(array)/4; // sizeof() -> runtime -> gives the size in bytes ==> /4 is needed
    for(int i = 0; i < length-1; i++)
    {
        if (array[i] == 5)
        {
            printf("array[%i] has the value of 2\n", i);
            return 0;
        }
    }
    printf("2 was not found!\n");
    return 1;
}
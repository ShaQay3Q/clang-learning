#include "./src/cs50.h"
#include <stdio.h>

void merge_sort(int numbers[], int length);


int main(void)
{
    int numbers[] = {5, 3, 4, 1};
    int length = sizeof(numbers) / sizeof(numbers[0]);


    merge_sort(numbers, length);
}

void merge_sort(int *numbers, int length)
{
        if (length == 0)
        {
            printf("No Exiting Set of Numbers!\n");
        }
        if (length == 1)
        {
            printf("%i", numbers[0]);
        }
        for (int i = 0; i < length; i++)
        {
            merge_sort(numbers, length);
        }
}
#include "./src/cs50.h"
#include <stdio.h>

void merge_sort(int numbers[], int length);
void printDigits(int *input, int length);


int main(void)
{
    int numbers[] = {5, 3, 4, 1};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    if (length == 0)        
    {
        printf("No Exiting Set of Numbers!\n");
    }
    merge_sort(numbers, length);
}

void merge_sort(int *numbers, int length)
{
    int subleft[length/2];
    int subright[length/2];
    for(int i = 0; i < (length/2 + 1); i++)
    {
        subleft[i] = numbers[i];
    }
    for(int j = 0; j < (length/2 + 1); j++)
    {
        subright[j] = numbers[length/2 + j];
    }
    printf("SubLeft: ");
    printDigits(subleft, length/2);

    printf("SubRight: ");
    printDigits(subright, length/2);
}

bool compare(int n1, int n2)
{
    return n1 < n2;
}

void printDigits(int *input, int length)
{
        for (int i = 0; i < length; i++)
            printf("%i", input[i]);
    printf("\n");
}
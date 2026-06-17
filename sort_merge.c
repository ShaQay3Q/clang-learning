#include "./src/cs50.h"
#include <stdio.h>

void merge_sort(int numbers[], int length);
void printDigits(int *input, int length);
void merge(int *subleft, int *subright, int subleft_length, int subright_length, int *numbers);

int main(void)
{
    // int left[] = {3, 5}; //4, 1};
    // int right[] = {1, 4};
    // int numbers[4];
    int numbers[] = {5, 3, 4, 1, 6, 2, 8, 9};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    // int ll = 2;
    // int lr = 2;
    
    merge_sort(numbers, length);
    // merge(left, right, ll, lr, numbers);
    // printDigits(numbers, 4);
}

void merge_sort(int *numbers, int length)
{    
    if(length < 1)
    {
        return;;
    }
    if(length == 1)
    {
        printDigits(numbers, length);
        return;
    }

    int subleft[length/2];
    int subright[length/2];

    for(int i = 0; i < (length/2); i++)
    {
        subleft[i] = numbers[i];
    }
    for(int j = 0; j < (length/2); j++)
    {
        subright[j] = numbers[length/2 + j];
    }
    
    // printf("SubLeft: ");
    // printDigits(subleft, length/2);

    // printf("SubRight: ");
    // printDigits(subright, length/2);

    merge_sort(subleft, length/2);
    merge_sort(subright, length/2);


    // int subleft_length = sizeof(subleft)/sizeof(subleft[0]);
    // int subright_length = sizeof(subright)/sizeof(subright[0]);
    // merge(subleft, subright, subleft_length, subright_length, numbers);
    
    merge(subleft, subright, length/2, length/2, numbers);

    printf("numbers: ");
    printDigits(numbers, length);
}




void merge(int *subleft,
    int *subright, 
    int subleft_length, 
    int subright_length, 
    int *numbers)
{
    int i = 0;
    int j = 0;
    int index = 0;
    // int min;
    // int numbers[subleft_length+subright_length];
    while(i < subleft_length && j < subright_length)
    {
        printf("i= %i\n", i);
        printf("j= %i\n", j);
        if (subleft[i] < subright[j])
        {
            numbers[index] = subleft[i];
            // printf("numbers[%i] = %i\n", index, numbers[index]);
            i++;
        }
        else
        {
            numbers[index] = subright[j];
            // printf("numbers[%i] = %i\n", index, numbers[index]);
            j++;
        }
        // printf("i= %i\n", i);
        // printf("j= %i\n", j);
        index++;
    }

    // drain whatever's left in subright
    while(j < subright_length)
    {
        numbers[index] = subright[j];
        j++;
        index++;
    }

    // drain whatever's left in subleft
    while (i < subleft_length)
    {
        numbers[index] = subleft[i];
        i++;
        index++;
    }
    // printDigits(numbers, 4);
}

void printDigits(int *input, int length)
{
        for (int i = 0; i < length; i++)
            printf("%i", input[i]);
    printf("\n");
}
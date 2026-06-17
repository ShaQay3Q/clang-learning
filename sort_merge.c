#include <stdio.h>

void merge_sort(int *numbers, int length);
void printDigits(int *input, int length);
void merge(int *subleft, int *subright, int subleft_length, int subright_length, int *numbers);

int main(void)
{
    int numbers[] = {5, 3, 4, 1, 6, 2, 8, 9};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    
    merge_sort(numbers, length);
    printDigits(numbers, length);
}

void merge_sort(int *numbers, int length)
{    
    if(length <= 1)
        return;

    int subleft[length/2];
    int subright[length/2];

    for(int i = 0; i < (length/2); i++)
        subleft[i] = numbers[i];
    merge_sort(subleft, length/2);


    for(int j = 0; j < (length/2); j++)
        subright[j] = numbers[length/2 + j];
    merge_sort(subright, length/2);
    
    merge(subleft, subright, length/2, length/2, numbers);
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

    while(i < subleft_length && j < subright_length)
    {
        if (subleft[i] < subright[j])
        {
            numbers[index] = subleft[i];
            i++;
        }
        else
        {
            numbers[index] = subright[j];
            j++;
        }
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
}

void printDigits(int *input, int length)
{
    for (int i = 0; i < length; i++)
        printf("%i", input[i]);
    printf("\n");
}
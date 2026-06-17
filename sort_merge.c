#include <stdio.h>

void merge_sort(int *numbers, int length);
void printDigits(int *input, int length);
void merge(int *subleft, int *subright, int subleft_length, int subright_length, int *numbers);

int main(void)
{
    int numbers[] = {5, 3, 4, 1, 6, 2, 8};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    
    merge_sort(numbers, length);
    printDigits(numbers, length);
}

void merge_sort(int *numbers, int length)
{     
    if(length <= 1)
        return;

    int length_left = length / 2;
    int length_right = length / 2;
   
    if (length % 2 == 1)
    {
        length_left = (length / 2 + 1);
    }
    int subleft[length_left];
    int subright[length_right];

    for(int i = 0; i < length_left; i++)
        subleft[i] = numbers[i];
    merge_sort(subleft, length_left);


    for(int j = 0; j < length_right; j++)
        subright[j] = numbers[length_left + j];
    merge_sort(subright, length_right);
    
    merge(subleft, subright, length_left, length_right, numbers);
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
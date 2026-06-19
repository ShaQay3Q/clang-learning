#include <stdio.h>
#include <assert.h>
#include <string.h>


void merge_sort(int *numbers, int left, int right);
void print_array(const int *input, int length);
void merge_two_arrays(int *subleft, int *subright, int subleft_length, int subright_length, int *numbers);

int main(void)
{
    // int numbers[] = {5, 3, 4, 1, 6, 2, 8};
    int numbers[] = {-5, 7, -2, 10, 3};
    // int numbers[] = {999};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    `

    merge_sort(numbers, left, depth);
    print_array(numbers, length);
}

void merge_sort(int *numbers, int left, int right)
{  
    int length = right - left + 1;
    int depth = 1;      
    for(int i = 0; i < depth; i++)
        printf("  ");

    // For tracking the length and depth of each recurtion - just a check!
    printf("merge_sort(length=%d, depth=%d)\n",
           length,
           depth);
    if (length <= 1)
        return;

    depth++;

      

    int length_left = length / 2;
    int length_right = length - length_left;
   
    int subleft[length_left];
    int subright[length_right];

    memcpy(subleft, numbers, length_left * sizeof(subleft[0]));

    for (int i = 0; i < length_left; i++)
        subleft[i] = numbers[i];
    merge_sort(subleft, length_left, depth);


    memcpy(subright,
       numbers + length_left,
       length_right * sizeof(subright[0]));

    for (int j = 0; j < length_right; j++)
        subright[j] = numbers[length_left + j];
    merge_sort(subright, length_right, depth);
    
    merge_two_arrays(subleft, subright, length_left, length_right, numbers);
}

void merge_two_arrays(int *subleft,
    int *subright, 
    int subleft_length, 
    int subright_length, 
    int *numbers)
{
    int i = 0;
    int j = 0;
    int index = 0;

    printf("merging array of length %d with array of length %d\n",
       subleft_length,
       subright_length);

    while (i < subleft_length && j < subright_length)
    {
        if (subleft[i] <= subright[j])
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

// const don't allow the function to modify the value and keep it only readable
void print_array(const int *input, int length)
{
    printf("The sort result: ");
    for (int i = 0; i < length; i++)
        printf("%i ", input[i]);
    printf("\n");
}
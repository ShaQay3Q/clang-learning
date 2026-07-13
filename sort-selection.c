#include <stdio.h>
#include <stdlib.h>

void swap(int input[], int index, int min_index);
void printDigits(int *input, int length);
void selection_sort(int *input, int length);
int parse_to_int(char *input[], int input_length, int output[]);
// RECURSIVE
int rec_find_min_index(int numbers[], int curr_index, int arr_length,  int min_index);
void rec_selection_sort(int numbers[], int arr_length, int start_index);

int main(int argc, char *argv[])
{
    
    int length = argc - 1;
    int numbers[length];
    parse_to_int(argv, argc, numbers);

    // selection_sort(numbers, length);

    // Print 
    // int arr[] = {64, 25, 12, 22, 11}; 
    rec_selection_sort(numbers, length, 0);
    printDigits(numbers, length);

}

void selection_sort(int *input, int length)
{
    int swapped = 0;

    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i;

        for (int curr_indexent_index = i + 1; curr_indexent_index < length; curr_indexent_index++)
        {
            if (input[curr_indexent_index] < input[min_index])
            {
                min_index = curr_indexent_index;
            }
        }

        if (min_index != i)
        {
            swap(input, i, min_index);
            swapped = 1;
        }

    }
    if (!swapped)
    {
        printf("Already sorted\n");
    }

    printf("Sorted: ");
    printDigits(input, length);
}

int parse_to_int(char *input[], int input_length, int output[])
{
    for(int i = 1; i < input_length; i++)
    {
        output[i - 1] = atoi(input[i]);
    }
    return 0;
}

void swap(int input[], int index, int min_index){
    int temp = input[index];
    input[index] = input[min_index];
    input[min_index] = temp;
}

void printDigits(int *input, int length){
    
        for (int i = 0; i < length; i++){
        printf("%i ", input[i]);
    }
    printf("\n");
}


int rec_find_min_index(int numbers[], int curr_index, int arr_length,  int min_index)
{
    // Error case
    if (numbers == NULL || arr_length == 0)
    {
        return -1;
    }
    // Base case
    if (curr_index >= arr_length)
    {
        return min_index;
    }
    // Recursive case 
    if (numbers[min_index] > numbers[curr_index])
    {
        min_index = curr_index;
    }
    return rec_find_min_index(numbers, curr_index + 1, arr_length, min_index);
}

void rec_selection_sort(int numbers[], int arr_length, int start_index)
{
    // Base case
    if (start_index >= arr_length - 1)
    {
        return;
    }

    // Recursive case
    int min_index = rec_find_min_index(numbers, start_index, arr_length, start_index);

    // Swap logic
    int temp = numbers[start_index];
    numbers[start_index] = numbers[min_index];
    numbers[min_index] = temp;

    return rec_selection_sort(numbers, arr_length, start_index + 1);
}
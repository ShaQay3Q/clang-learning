#include <stdio.h>
#include <stdlib.h>

void swap(int *input, int index, int index_min);
void printDigits(int *input, int length);
void selection_sort(int *input, int length);
int parse_to_int(char *input[], int length, int output[]);


int main(int argc, char *argv[]){
    
    int length = argc - 1;
    int numbers[length];
    parse_to_int(argv, argc, numbers);

    selection_sort(numbers, length);

}

void selection_sort(int *input, int length)
{
    int index_min;

    for (int i = 0; i < length - 1; i++)
    {
        index_min = i;

        for (int current_index = i + 1; current_index < length; current_index++)
        {
            if (input[current_index] < input[index_min])
            {
                index_min = current_index;
            }
        }

        if (index_min != i)
        {
            swap(input, i, index_min);
        }
    }

    printf("Sorted: ");
    printDigits(input, length);
}

int parse_to_int(char *input[], int length, int output[])
{
    for(int i = 1; i < length; i++)
    {
        output[i - 1] = atoi(input[i]);
    }
    return 0;
}

void swap(int *input, int index, int index_min){
    int temp = input[index];
    input[index] = input[index_min];
    input[index_min] = temp;
}

void printDigits(int *input, int length){
    
        for (int i = 0; i < length; i++){
        printf("%i", input[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdbool.h>

void swap(int *numbers, int i, int iMin);
void printDigits(int *Arr, int length);
void bubble_sort(int *numbers, int length);


int main(void)
{
    // int numbers[] = {2, 8, 5, 3, 9, 4, 1};
    int numbers[] = {5, 3, 4, 1};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    bubble_sort(numbers, length);
    printDigits(numbers, length);
    return 0;
}

void printDigits(int *Arr, int length)
{

  for (int i = 0; i < length ; i++)
  {
    printf("%i", Arr[i]);
  }
  printf("\n");
}

void swap(int *numbers, int i, int iMin)
{
  int temp = numbers[iMin];
  numbers[iMin] = numbers[i];
  numbers[i] = temp;
}

void bubble_sort(int *numbers, int length)
{    
    bool swapped;
    printDigits(numbers, length);

    for(int i = 0; i < length - 1; i++)
    {
        swapped = false;
        printf("i: %i\n", i);

        for(int j = 0; j < length - i - 1; j++)
        {
            printf("j: %i\n", j);

            if(numbers[j] > numbers[j + 1])
            {
                swap(numbers, j, j+1);
                swapped = true;
            }
            printDigits(numbers, length);
        }
    if(!swapped)
        {
            break;
        }
   }
}
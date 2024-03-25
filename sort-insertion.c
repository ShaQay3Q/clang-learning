#include <stdio.h>

void swap(int *intArr, int i, int j);
void printDigits(int *Arr, int length);
void insertation_sort(int *intArr, int length);

int main(void){
    int initArr[] = {2, 8, 5, 3, 9, 4, 1};
    int arrLength = 7;

    insertation_sort(initArr, arrLength);

    printf("Insert sort: ");
    printDigits(initArr, arrLength);
}

void swap(int *intArr, int i, int iMin){
    int temp = intArr[iMin];
    intArr[iMin] = intArr[i];
    intArr[i] = temp;
}

void printDigits(int *Arr, int length){
    
        for (int i = 0; i < length; i++){
        printf("%i", Arr[i]);
    }
    printf("\n");
}

void insertation_sort(int *intArr, int length){
    for (int i = 0; i < length; i++){
        for (int j = i; j > 0; j--){
            if (j > 0 && intArr[j-1] > intArr[j]){
                swap(intArr, j, j-1);
            }
        }
    }   
}
#include <stdio.h>

void swap(int *initArr, int iIndex, int iMin);
void printDigits(int *Arr, int length);
void selection_sort(int *initArr, int arrLength);


int main(void){

    int numArr[] = {2, 8, 5, 3, 9, 4, 1};
    int arrLength = 7;
    selection_sort(numArr, arrLength);

}

void selection_sort(int *initArr, int arrLength){
        int iMin;
    
    for (int i = 0; i < arrLength -1 ; i++){
        iMin = i;
        for (int iCurrent = i+1; iCurrent < arrLength; iCurrent++) {
            if (initArr[iCurrent]<initArr[iMin]) {
                iMin = iCurrent;
            }
            if (iMin != i) {
                swap(initArr, i, iMin);
            }
        }
    }
    printf("Sorted: ");
    printDigits(initArr, arrLength);
}

void swap(int *initArr, int iIndex, int iMin){
    int temp = initArr[iIndex];
    initArr[iIndex] = initArr[iMin];
    initArr[iMin] = temp;
}

void printDigits(int *Arr, int length){
    
        for (int i = 0; i < length; i++){
        printf("%i", Arr[i]);
    }
    printf("\n");
}
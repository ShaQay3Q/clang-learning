#include "./src/cs50.h"
#include <stdio.h>

void swap(int *initArr, int iIndex, int iMin);
void printDigits(int *Arr, int length);
void selection_sort(int *initArr, int arrLength);


int main(void){

    int numArr[] = {2, 8, 5, 3, 9, 4, 1};
    printf("initial digits: ");
    printDigits(numArr, 7);

    swap(numArr, 6, 0);

    printf("digits after the first swap: ");
    printDigits(numArr, 7);

    swap(numArr, 1, 6);

    printf("digits after the second swap: ");
    printDigits(numArr, 7);

}

// void selection_sort(int *initArr, int arrLength){
//     int iMin;
//     int i;
//     for (i = 0; i < arrLength - 1; i++){
//         iMin = i;
//     }
//     for (int currItm = i+1; currItm<arrLength; currItm++){
//         if (initArr[currItm] < initArr[iMin]){
//             iMin = currItm;
//         }
//     }
//     if (iMin != i) {
//         swap(initArr, i, iMin);
//     }

    
//     printf("Sorted: ");
//     for (int j = 0; i < arrLength; j++){
//         printf("%i", initArr[j]);
//     }
//     printf("\n");
// }

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
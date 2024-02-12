#include "./src/cs50.h"
#include <stdio.h>

void print_piramid(int n);


int main(void){
    int i = get_int("piramid: ");
    print_piramid(i);
}

void print_piramid(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (i+1); j++){
            printf("#");
        }

        printf("\n");
    }
}
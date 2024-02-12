#include "./src/cs50.h"
#include <stdio.h>

void print_piramid(int n);
void print_another_piramid(int n);


int main(void){
    int i = get_int("piramid: ");
    int j = get_int("second piramid: ");
    print_another_piramid(j);
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


void print_row(int n){
    for (int i; i < (n+1); i++){
        printf("#");
    }
}

void print_another_piramid(int n){
    for (int i; i < n; i++){
        print_row(i);
        printf("\n");
    }
}
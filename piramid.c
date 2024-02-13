#include "./src/cs50.h"
#include <stdio.h>

//void print_a_piramid(int n);
void print_piramid(int n);
void print_a_piramid(int n);


int main(void){
    int i = get_int("piramid: ");
    print_piramid(i);
}


void print_a_piramid(int n){
    for (int i = 0; i < n; i++){
        for (int v = (n-i); v > 0; v--){
            printf(" ");
        }
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

void print_free_space(int n, int i){
    for (int v = (n - i); v > 0; v--){
        printf(" ");
    }
}

void print_piramid(int n){
    for (int i = 0; i < n; i++){
        print_free_space(n, i);
        print_row(i);
        printf("\n");
    }
}
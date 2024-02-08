#include<stdio.h>
#include <stdbool.h>

int main(void){
    int i = 0;
    while (i < 3){
        printf("meow!\n");
        i++;
    }

    printf("\n");

    for (int i = 0; i < 5; i++){
        printf("maow!\n");
    }

    printf("\n");

    while (true){
        printf("meow!\n");
    }
}
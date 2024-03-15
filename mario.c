#include "./src/cs50.h"
#include <stdio.h>
#include <stdlib.h>

int get_size(void);
void print_grid(int size);


int main(int argc, string argv[]) {

    if (argc == 1){
        printf("Not enough arguments!\nFollow: ./mario <number>\n");
        return 1;
    }
    for(int i = 1; i < argc; i++){

        int n = atoi(argv[i]);
        if (n == 0) {

            printf("argv[%i] = 0\n", i);

        } else {

            print_grid(n);
        }
        return 0;
    }
}

int get_size(void) {
    int n;
    do {
        n = get_int("Set size: ");
    } while (n < 1);
    return n;
}

// print_grid prints grid of bricks
void print_grid(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("#");
        }
        printf("\n");
    }
}


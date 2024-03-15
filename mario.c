#include "./src/cs50.h"
#include <stdio.h>
#include <stdlib.h>

int get_size(void);
void print_grid(int size);


int main(int argc, string argv[]) {

  // int n = get_int("set the size of the grid: ");

  // while (n<1){
  //     printf("Please enter a Natural Number");
  //     n = get_int(": ");
  // }

  // Get the size of grid
    for(int i = 1; i<argc; i++){

        int n = atoi(argv[i]);
        // int n = get_size();

        // Print grid of bricks
        print_grid(n);
    }

}

int get_size(void) {
    int n;
    do {
        n = get_int("Set size: ");
    } while (n < 1);
    return n;
}
void print_grid(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("#");
        }
        printf("\n");
    }
}


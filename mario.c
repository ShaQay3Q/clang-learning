#include <stdio.h>
#include <stdlib.h>

void print_grid(int size);
void print_row(int size);



int main(int argc, char *argv[]) {
    if (argc == 1){
        printf("Not enough arguments!\nFollow: ./mario <number>\n");
        return 1;
    }
    int n = atoi(argv[1]);

    if(n < 0)
    {
        printf("Realy?!\n");
        return 1;
    } else if (n == 0)
    {
        printf("Come on! Do you really wanna see no blocks at all!\n");
        return 1;
    } else {

        print_grid(n);
    }
    return 0;
}

// print_grid prints grid of bricks
void print_grid(int size) {
    for (int i = 0; i < size; i++) {
        print_row(i + 1);
    }
}

//print_row prints row of bricks
void print_row(int size)
{
    for(int i = 0; i < size; i++){
        printf("#");
    }
    printf("\n");
}
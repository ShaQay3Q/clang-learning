#include <stdio.h>
#include "./src/cs50.h"


int main(int argc, string argv[]){

    // string name = get_string("What is your name?\n");
    // printf("Hello, %s\n", name);

    // printf("Hello, %s\n", argv[1]);

    if (2 <= argc && argc <= 3){
        printf("Hello, %s %s\n", argv[1], argv[2]);
    } else {
        printf("Hello, World!\n");
    }
}
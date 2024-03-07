#include "./src/cs50.h"
#include <stdio.h>


// int can be printed by <echo $?> on terminal
int main(int argc, string argv[]){
    if (argc <2){
        printf("Missing Command-line Argument!\n");
        return 1;
    } else {
        printf("Hello, %s\n", argv[1]);
        return 0;
    }
}
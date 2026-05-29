#include "./src/cs50.h"
#include <stdio.h>

//argc -> argument count
//argv -> argument vector
int main(int argc, string argv[]){

    for(int i = 0; i < argc; i++){
        printf("argv[%i]: %s\n", i, argv[i]);
    }
}
#include <stdio.h>
#include "./src/cs50.h"


int main(int argc, string argv[])
{
    if (argc == 1 ) {
        printf("Usage: ./greet name\n");    
    } else {
        for(int i = 0; i < argc; i++){
        printf("Hello, %s!\n", argv[i]);

        }
    }
    for(int i = 0; i < argc; i++){
        printf("argv[%i] -> %s\n", i, argv[i]);
    }
}
#include <stdio.h>
#include "./src/cs50.h"


int main(int argc, string argv[])
{
    if (argc == 1 ) {
        printf("Usage: ./greet name\n");    
    } else {
        printf("Hello, %s!\n", argv[1]);
    }
    for(int i = 0; i < argc; i++){
        printf("argv[%i] -> %s\n", i, argv[i]);
    }
}
#include "./src/cs50.h"
#include <stdio.h>
#include <string.h>

int main(void){

    string name = get_string("Name: ");

    int i = 0;
    while(name[i] != '\0'){
        i++;
    }
    printf("length: %i\n", i);

    int l = strlen(name);

    printf("name length: %i\n", l);
}
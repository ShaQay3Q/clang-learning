#include "./src/cs50.h"
#include <stdio.h>

int array_of_doubles(int array_length, int array_name[]);
void print_array(int length, int name[]);

int main(void){
    
    int arrayLength = get_int("How many numbers to display? >: ");
    int doubles[arrayLength];
    
    while (arrayLength == 0){
        arrayLength = get_int("How many numbers to display? >: ");
    }
    print_array(arrayLength, doubles);

    
}

int array_of_doubles(int array_length, int array_name[]){

    int n = 1;
    for (int i = 0; i < array_length; i++){
        n = n * 2;
        array_name[i] = n;
    }
    return array_name[array_length];
}

void print_array(int length, int name[]){
    
    // Seems this one is correct too! At least it works. WHY?

    name[length] = array_of_doubles(length, name);
    for (int i = 0; i < length; i++){
        printf("index %i: value %i\n", i, name[i]);
    }
}

#include "./src/cs50.h"
#include <stdio.h>

int array_of_doubles(int array_length, int array_name[]);
void print_array(int length, int name[]);
int array_of_doubles02(int array_length, int array_name[]);

int main(void){
    
    int arrayLength = get_int("How many numbers to display? >: ");
    int doubles[arrayLength];
    
    while (arrayLength == 0){
        arrayLength = get_int("How many numbers to display? >: ");
    }
    print_array(arrayLength, doubles);
}

int array_of_doubles01(int array_length, int array_name[]){

    int n = 1;
    for (int i = 0; i < array_length; i++){
        array_name[i] = n;
        n = n * 2;
    }
    return array_name[array_length];
}

// this one looks interesting.
// I will try to impliment this style for solving similar problems later
int array_of_doubles02(int array_length, int array_name[]){

    array_name[0] = 1;
    for (int i = 1; i < array_length; i++){
        array_name[i] = array_name[i-1] * 2;
    }
    return array_name[array_length];
}


void print_array(int length, int name[]){
    
    // Seems this one is correct too! At least it works. WHY?

    name[length] = array_of_doubles02(length, name);
    for (int i = 0; i < length; i++){
        printf("index %i: value %i\n", i, name[i]);
    }
}

#include "./src/cs50.h"
#include <stdio.h>

int array_of_doubles(int array_length, int array_name[]);
void print_array(int length, int name[]);
int array_of_doubles02(int array_length, int array_name[]);
void fill_print_array01(int length, int name[]);


int main(void){
    
    int arrayLength = get_int("How many numbers to display? >: ");
    int doubles[arrayLength];
    
    while (arrayLength == 0){
        arrayLength = get_int("How many numbers to display? >: ");
    }
    print_array(arrayLength, doubles);

    int arrayOfDoubles[arrayLength];

    fill_print_array01(arrayLength, arrayOfDoubles);
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

void fill_print_array01(int length, int name[]){

    name[0] = 1;
    printf("index %i: %i\n", 1, name[0]);
    for (int i = 1; i < length; i++){
        name[i] = name[i-1]*2;
        printf("index %i: %i\n", i, name[i]);
    }
}


// how to set name[0] as 1 and solving the problem only by using the loop?!
// void fill_print_array02(int length, int name[]){

//     for (int i = 1; i < length; i++){
//         name[0] = i;
//         printf("index %i: %i\n", i, name[i]);
//     }
// }
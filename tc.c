#include <stdio.h>
#include "./src/cs50.h"

int main(void){

    long x = get_long("x: ");
    long y = get_long("y: ");

    // type casting -> convert one data type to another data type by making it explicit to the compiler
    double z = (double) x / (double) y;
    
    printf("%.20f\n", z);
}
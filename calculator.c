#include <stdio.h>
#include "./src/cs50.h"

float summation(float x, float y);
float substraction(float x, float y);
float multipication(float x, float y);
float division(float x, float y);

int main(void){

    float x = get_float("x: ");
    float y = get_float("y: ");
    char operant = get_char("operant: ");

    if (operant == '+'){
            printf("= %f\n", summation(x, y));
    } else if (operant == '-'){
            printf("= %f\n", substraction(x, y));
    } else if (operant == '*'){
        printf("= %f\n", multipication(x, y));
    } else if (operant == '/'){
            printf("= %f\n", division(x, y));
    }
}

float summation(float x, float y){
    return x+y;
}

float substraction(float x, float y){
    return x-y;
}

float multipication(float x, float y){
    return x*y;
}

float division(float x, float y){
    return x/y;
}
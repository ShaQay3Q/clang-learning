#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) //pointer to pointer -> char *argv[] / char **argv
{
    if(argc != 4)
    {
        printf("Usage: ./calc number operator number\n");
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[3]);
    double c;
    char operator = (char)argv[2][0];

    if (operator == '+')
    { c =  a + b;}
    else if (operator == '-') {
        c = a - b ;
    } else if(operator == '*'){
        c = a * b;
    } else {
        c =  a / b;
    }

    printf("%g %c %g = %g\n", a, operator, b, c);
}
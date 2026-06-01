#include <stdio.h>

int main(void)
{
    int num1, num2, sum;

    printf("Enter the first number: \n");
    scanf("%d", &num1);

    printf("Enter another number: \n");
    scanf("%d", &num2);

    sum = num1 + num2;

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    return 0;
}
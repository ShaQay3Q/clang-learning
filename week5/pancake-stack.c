#include <stdio.h>

int main(void)
{
    // Create a stack array with space for 3 items
    int stack[3];
    int top = -1; // -1 means the stack is currently empty!

    // TODO: Push 3 numbers onto the stack (Hint: increment top, then add the number)
    // top++;
    // stack[top] = 10;
    top = top + 1;
    stack[top] = 10;

    top = top + 1;
    stack[top] = 20;

    top = top + 1;
    stack[top] = 30;

    // TODO: Pop and print the numbers in reverse order using a loop or manual prints
    for(int i = top; i > -1; i--)
    {
        printf("%i\n", stack[i]);
    }
    return 0;
}
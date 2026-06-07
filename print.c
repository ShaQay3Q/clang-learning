#include "./src/cs50.h"
#include <stdio.h>
#include <string.h>

int print_it(string input);

int main(void)
{
    string input = get_string("Enter your name: ");
    print_it(input);
    return 0;
}

int print_it(string input)
{
    for (int i = 0, l = strlen(input); i < l; i++)
    {
        printf("%c",input[i]);
    }
    printf("\n");
    return 0;
}

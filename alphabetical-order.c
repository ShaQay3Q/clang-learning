#include "./src/cs50.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


int main(void)
{
    string input = get_string("Enter your input in all lowcase letters: ");
    int counter = 0, l = strlen(input);

    for (int i = 0; i < l-1; i++)
    {
        if(input[i] > input[i+1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
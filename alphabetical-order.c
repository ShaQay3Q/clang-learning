#include "./src/cs50.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool compare(char c1, char c2);

int main(void)
{
    string input = get_string("Enter your input in all lowcase letters: ");
    int counter = 0, l = strlen(input);

    for (int i = 0; i < l-1; i++)
    {
        if(compare(input[i], input[i+1]))
        {
            counter++;
        }   
    }
    if (counter == l - 1)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 1;

}

bool compare(char c1, char c2)
{
    return c1 < c2;
}
#include "./src/cs50.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    string names[] = {"Aida", "Anran", "Ensi", "Maryam", "Natia"};
    int numbers[] = {7, 10, 13, 1, 20};

    string name = get_string("Name: ");

    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", names[i]);
        if(strcmp(names[i], name) == 0)
        {
            printf("%s number is %i\n", name, numbers[i]);
            return 0;
        }

    }
    printf("%s Not Found!\n", name);
    return 1;
}
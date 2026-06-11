#include "./src/cs50.h"
#include <string.h>
#include <stdio.h>

// create specific data type in C
typedef struct
{
    string name;
    int number;
} person;

int main(void)
{

    person people[] =
    {
        {"Aida", 7},
        {"Anran", 10},
        {"Ensi", 13},
        {"Maryam", 1},
        {"Natia", 20}
    };

    string name = get_string("Name: ");

    for(int i = 0; i < 5; i++)
    {
        if(strcmp(people[i].name, name) == 0)
        {
            printf("%s number is %i\n", name, people[i].number);
            return 0;
        }
    }
    printf("%s Not Found!\n", name);
    return 1;
}
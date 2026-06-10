#include "./src/cs50.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("Search for a name: ");
    string names[] = {"Anna", "Lisa", "Amou", "Sha", "Leandro", "Aida", "Maryam", "Gigi", "Anran", "Ray", "Meike", "Cora"};
    int length = (int)sizeof(names)/4; // sizeof() -> runtime -> gives the size in bytes ==> /4 is needed
    for(int i = 0; i < length-1; i++)
    {
        if (strcmp(names[i], name))
        {
            printf("%s -> Found!\n", name);
            return 0;
        }
    }
    printf("%s -> Not Found!\n", name);
    return 1;
}
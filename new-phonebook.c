#include "./src/cs50.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "w"); // "w" for write

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
    return 0;
}


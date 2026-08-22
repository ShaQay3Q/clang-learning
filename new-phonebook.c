#include "./src/cs50.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "w"); // "w" for write
    if (file == NULL)
    {
        return 1;
    }
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);
    
    // write on therminal!
    fprintf(stdout, "DONE!\n"); 
    
    // close the open file, clearup the allocated memory
    fclose(file);
    return 0;
}


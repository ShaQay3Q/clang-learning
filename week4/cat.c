#include <stdio.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <source>.\n", argv[0]);
        return 2;
    }
    int c;
    FILE *input = fopen(argv[1], "rb"); // read in binanry mode
    if (input == NULL)
    {
        fprintf(stderr, "Error: could not open %s.\n", argv[1]);
        return 3;
    }
    while ((c = fgetc(input)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n'");
    fclose(input);
    return 0;
}

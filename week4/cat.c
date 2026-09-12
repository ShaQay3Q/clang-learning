#include <stdio.h>

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stdout, "Usage: %s filename.\n", argv[0]);
        return 2;
    }
    int c;
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stdout, "Error!\nCould not open %s.\n", argv[1]);
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

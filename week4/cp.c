#include <stdio.h>

int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stdout, "Usage: %s original-file-name copy-name.\n", argv[0]);
        return 1;
    }

    int c;

    FILE *input = fopen(argv[1], "rb"); // read in binanry mode
    if (input == NULL)
    {
        fprintf(stderr, "Error: could not open %s.\n", argv[1]);
        return 2;
    }

    FILE *output = fopen(argv[2], "wb"); // write in binanry mode
    if (output == NULL)
    {
        fclose(input);
        fprintf(stdout, "Error: could not create a copy of %s!\n", argv[1]); 
        return 3;
    }
    while ((c = fgetc(input)) != EOF)
    {
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
    printf("DONE!\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE ;


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename.pdf.\n", argv[0]);
        return 1;
    }

    size_t l = strlen(argv[1]);
    if (l < 5)
    {
        printf("Error: filename must contain at least one character.\n");
        return 2;
    }

    const char signature[] = "%PDF-";
    BYTE header[1024];
    size_t b_read;

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Error: could not open input file.\n");
        return 3;
    }

    b_read = fread(header, 1, sizeof(header), input);

    for (size_t i = 0; i + 5 < b_read; i++)
    {
        // memcmp() compares the contents of two regions of memory, byte by byte.
        // compares a slice of memory with range of 5 to the array
        if ((memcmp(signature, header + i, 5)) == 0)
        {
            fprintf(stdout, "%s is a PDF file\n", argv[1]);        
            fclose(input);
            return 0;
        }
    }

    printf("%s is NOT a PDF file!\n", argv[1]);
    fclose(input);
    return 1;
}
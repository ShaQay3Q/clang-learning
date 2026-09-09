#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


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

    const uint8_t signature[4] = {0x25, 0x50, 0x44, 0x46};
    uint8_t header[1024];
    size_t buffer;

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Error: could not open input file.\n");
        return 3;
    }

    buffer = fread(header, 1, sizeof(header), input);

    for (size_t i = 0; i + 4 < buffer; i++)
    {
        // memcmp() compares the contents of two regions of memory, byte by byte.
        // compares a slice of memory with range of 5 to the array
        if ((memcmp(signature, header + i, 4)) == 0)
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
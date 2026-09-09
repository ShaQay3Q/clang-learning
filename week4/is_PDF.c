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
        return 2;
    }

    size_t l = strlen(argv[1]);
    if (l < 5)
    {
        printf("Error: filename must contain at least one character.\n");
        return 3;
    }

    const uint8_t signature[5] = {0x25, 0x50, 0x44, 0x46, 0x2D};
    uint8_t header[1024];
    size_t bytes_read;

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Error: could not open input file.\n");
        return 4;
    }

    bytes_read = fread(header, 1, sizeof(header), input);
    
    // close the stream right after reading the header into bytes_read
    fclose(input);

    for (size_t i = 0; i + 5 < bytes_read; i++)
    {
        // memcmp() compares the contents of two regions of memory, byte by byte.
        // Compares a slice of memory with specific range to an array
        // Compare the next 5 bytes with the PDF signature "%PDF-"
        if ((memcmp(signature, header + i, 5)) == 0)
        {
            fprintf(stdout, "%s is a PDF file\n", argv[1]);        
            return 0;
        }
    }

    printf("%s is NOT a PDF file!\n", argv[1]);
    return 1;
}
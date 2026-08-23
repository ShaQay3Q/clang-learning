#include <stdio.h>

// BYTE is an alias for unsigned char, used here to represent raw byte values
typedef unsigned char BYTE ;

int main(int argc, char *argv[])
{
    // ERROR handling - correct number of arguments
    if (argc != 3)
    {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb"); // read in ninary mood
    FILE *dst = fopen(argv[2], "wb"); // writ ein binary mood

    // ERROR handling - NULL
    if (src == NULL)
    {
        return 1;
    }

    if (dst == NULL)
    {
        fclose(src);
        return 1;
    }

    // an extremely tiny buffer capable of holding one byte
    BYTE b;
    size_t b_read;

    while((b_read = fread(&b, sizeof(b), 1, src)) > 0)
    {
        fwrite(&b, sizeof(b), b_read, dst);
    }

    fclose(dst);
    fclose(src);

    return 0;
}
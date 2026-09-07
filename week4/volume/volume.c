#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

bool has_same_format(char const *input, char const *format);
bool is_filename_acceptable(char const *input);
bool is_valid_factor(const char *factor, float *f);

// BYTE is an alias for unsigned char, used here to represent raw byte values
typedef unsigned char BYTE ;


int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 4)
    {
        printf("Usage: %s input.wav output.wav factor\n", argv[0]);
        return 1;
    }

    float f;

    // Validate the arguments
    if (!is_filename_acceptable(argv[1]) ||
    !is_filename_acceptable(argv[2]) ||
    !is_valid_factor(argv[3], &f))
    {
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb"); // write in binary mode

    // ERROR handling - NULL
    if (src == NULL)
    {
        printf("Error: could not open input file.\n");
        return 1;
    }
    if (dst == NULL)
    {
        printf("Error: could not open output file.\n");
        fclose(src);
        return 1;
    }

    BYTE header[44];
    size_t b_read;

    // fread() returns the number of complete items read
    //b_read should be 1
    b_read = fread(header, sizeof(header), 1, src);
    
    // check for complete header read
    if (b_read != 1)
    {
        printf("Error: failed to read WAV header.\n");
        fclose(src);
        fclose(dst);
        return 1;
    }
    fwrite(header, sizeof(header), b_read, dst);

    int16_t sample;    // one 16-bit audio sample
    
    while((b_read = fread(&sample, sizeof(sample), 1, src)) > 0)
    {
        sample = sample * f;
        fwrite(&sample, sizeof(sample), b_read, dst);
    }


    fclose(src);
    fclose(dst);
    return 0;
}


bool has_same_format(char const *input, char const *format)
{
    size_t szinput = strlen(input);
    size_t szformat= strlen(format);

    if (szinput < szformat) return false; // NO

    // if (strcmp(&input[szinput - szformat], format) != 0) return false;
    if (strcmp(input + (szinput - szformat), format) != 0) return false;
    
    return true; // YES
}

// Vlidate argv[1] and argv[2]
bool is_filename_acceptable(char const *input)
{
    if (strlen(input) < 5)
    {
        printf("Error: filename must contain at least one character before the .wav extension.\n");
        return false;
    }

    // compare for correct format
    if (!has_same_format(input, ".wav"))
    {
        printf("Error: filename must have a .wav extension.\n");
        return false;
    }

    return true;
}

// Vlidate argv[3]
bool is_valid_factor(const char *factor, float *f)
{
    char *end;
    *f = strtof(factor, &end);

    if (end == factor)
    {
        printf("Error: factor must be a number.\n");
        return false;
    }

    if (*end != '\0')
    {
        printf("Error: factor must contain only a number.\n");
        return false;
    }

    if (*f < 0)
    {
        printf("Error: factor must not be negative.\n");
        return false;
    }

    return true;
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool has_same_format(char const *input, char const *format);
bool is_filename_acceptable(char const *input);
bool is_valid_factor(const char *factor, float *f);

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


    fprintf(stdout, "f: %f\n",f);




    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) return 1;




    fclose(file);
    return 0;

}

//   char *format = ".wav";
//   if (has_same_format(argv[1], format)) return 1;


bool has_same_format(char const *input, char const *format)
{
    size_t szinput = strlen(input);
    size_t szformat= strlen(format);

    if (szinput < szformat) return false; // NO

    // if (strcmp(&input[szinput - szformat], format) != 0) return false;
    if (strcmp(input + (szinput - szformat), format) != 0) return false;
    
    return true; // YES
}

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
        printf("Error: input file must have a .wav extension.\n");
        return false;
    }

    return true;
}

bool is_valid_factor(const char *factor, float *f)
{
    char *end;
    *f = strtof(factor, &end);
    fprintf(stdout, "%f\n",  *f);
    fprintf(stdout, "%c\n", *end);

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
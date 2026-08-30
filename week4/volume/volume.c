#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

bool has_same_format(char const *input, char const *format);
bool is_filename_acceptable(char const *input);


int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 4)
    {
        printf("Usage: %s input.wav output.wav factor\n", argv[0]);
        return 1;
    }

    // Check the input and outout name and format
    if (!is_filename_acceptable(argv[1]) || !is_filename_acceptable(argv[2]))
    {
        return 1;
    }

    // convert the factor into float
    char *end;
    float f = strtof(argv[3], &end);
    fprintf(stdout, "%f\n",  f);


    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) return 1;
    



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

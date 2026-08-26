#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool has_same_format(char const *input, char const *format);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s *.wav\n", argv[0]);
        return 1;
    }

    if (strlen(argv[1]) < 5)
    {
        printf("Error: filename must contain at least one character before the .wav extension.\n");
        return 1;
    }

    if (!has_same_format(argv[1], ".wav"))
    {
        printf("Error: file must have a .wav extension.\n");
        return 1;
    }

    return 0;

}

//     char *format = ".wav";
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

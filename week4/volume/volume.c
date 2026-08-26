#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    if (argc != 0)
    {
        printf("Usage: %s *.wav\n", argv[0]);
        return 1;
    }

    if (strlen(argv[1]) < 5)
    {
        printf("Error\n");
        return 1;
    }

    return 0;

}


bool has_same_format(char const *input, char const *format) {
    size_t szinput = strlen(input);
    size_t szformat= strlen(format);

    if (szinput < szformat) return false; // NO

    // if (strcmp(&input[szinput - szformat], format) != 0) return false;
    if (strcmp(input + (szinput - szformat), format) != 0) return false;
    
    return true; // YES
}

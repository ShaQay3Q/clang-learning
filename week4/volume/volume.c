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


int compare_last_format_characters(char const *input, char const *format) {
    size_t szinput = strlen(input);
    size_t szformat= strlen(format);

    if (szinput < szformat) return 1;
    
    char *input_format = malloc((szformat + 1) * sizeof(char));
    
    if (input_format == NULL) return 1;
    
    for(size_t i = 0; i < szformat + 1 ;i++)
    {
        input_format[szformat - i] = input[szinput - i];
    }

    int result = strcmp(input_format, format);

    free(input_format);

    if (result != 0) return 1;
    
    return 0;
}

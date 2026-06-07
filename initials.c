#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[5])
{
    if (argc < 2)
    {
        printf("Usage: ./initials Fistname Lastname\n");
        return 0;
    }
    for(int i = 1; i < argc; i++)
    {
        printf("%c", toupper(argv[i][0]));
    }
    printf("\n");
    return 0;
}
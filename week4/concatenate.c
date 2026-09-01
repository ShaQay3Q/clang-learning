#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char *s1, char *s2);


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s string string\n", argv[0]);
        return 1;
    }

    char *s3 = concat(argv[1], argv[2]);

    printf("cancatenate string: %s\n", s3);

    free(s3);
    
    return 0;
}

char *concat(char *s1, char *s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    char *str = malloc(sizeof(char) * (l1 + l2) + 1);
    if (str == NULL)
    {
        printf("Not enough memory to allocate!\n");
        return NULL;
    }

    for (int i = 0; i < l1; i++)
    {
        str[i] = s1[i];
    }
    for (int i = 0; i < l2; i++)
    {
        str[l1 + i] = s2[i];
    }
    str[l1+l2] = '\n';
    printf("%s\n", str);

    return str;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        printf("Error: Memory could not be allocated!\n");
        return 1;
    }

    list[0] = 1;
    *(list + 1)  = 2;
    list[2] =  3;

    // Re-allocate memory => either allocate more contagious memories
    // or allocate anothe rpart of memory and do the copying
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        printf("Error: Memory could not be allocated!\n");
        free(list);
        return 1;
    }

    tmp[3] = 4;
    list = tmp;

        for (int i = 0; i < 4; i++)
    {
        printf("%i ", list[i]);
    }
    printf("\n");

    free(list);
    return 0;
}
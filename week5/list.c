#include <stdio.h>
#include <stdlib.h>
#include "../src/cs50.h"


typedef struct node
{
    int number;
    struct node *next;

} node; // convention

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 3; i++)
    {
        node *tmp_node = malloc(sizeof(node));
        if (tmp_node == NULL)
        {
            fprintf(stderr,  "Error: not enough memory!\n");
            return 1;
        }
        // dereference op.
        (*tmp_node).number = get_int("Enter a number: ");
        tmp_node->next = list;

        // Prepend node to list
        list = tmp_node;
    }

    // Print numbers
    // node *ptr = list;
    // while (ptr != NULL)
    for(node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    
    return 0;
}
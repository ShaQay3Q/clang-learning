#include <stdio.h>
#include <stdlib.h>
#include "../src/cs50.h"

typedef struct node
{
    int number;
    struct node *next;

} node; // convention

// Prototype - Helper functions
void unload(node *list);


int main(void)
{
    node *list = NULL;

    for (int i = 0; i < 5; i++)
    {
        node *tmp_node = malloc(sizeof(node));
        if (tmp_node == NULL)
        {
            fprintf(stderr,  "Error: not enough memory!\n");
            unload(list);
            return 1;
        }
        // dereference op.
        (*tmp_node).number = get_int("Enter a number: ");
        tmp_node->next = NULL;


        // Prepend node to list
        // If list is empty
        if(list == NULL)
        {
            // tmp_node->next = list;
            // This node is the whole list
            list = tmp_node;
        }
        // If numebr belongs to the begining of the list
        else if (tmp_node->number < list->number)
        {
            tmp_node->next = list;
            list = tmp_node;
        }
        // If the number belongs later in the list
        else
        {
            // Iterate over the nodes in the list
            for(node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at the end of the list
                if(ptr->next == NULL)
                {
                    // Apend one node
                    ptr->next = tmp_node;
                    break;
                }
                // If in the middle of the list
                if(tmp_node->number < ptr->next->number)
                {
                    tmp_node->next = ptr->next;
                    ptr->next = tmp_node;
                    break;
                }
            }
            
        }

    }

    // Print numbers
    node *ptr = list;
    while (ptr != NULL) // MORE READBALE!!!
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    // for(node *ptr = list; ptr != NULL; ptr = ptr->next)
    // {
    //     printf("%i\n", ptr->number);
    // }
    
    // Free memory
    unload(list);

    return 0;
}

void unload(node *list)
{
    node *ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
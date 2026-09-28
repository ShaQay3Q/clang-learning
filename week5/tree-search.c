#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Data type definition
typedef struct node{
    int number;
    struct node *left;
    struct node *right;
} node;

// Prototype
bool search(node *tree, int number);

int main(void)
{
    node *tree = NULL;
    

    return 0;
}

node *insert(node *tree, int number)
{

}

bool search(node *tree, int number)
{
    // Base case 1: no number found
    if (tree == NULL)
    {
        return false;
    }
    // Base case 2: number found
    if (number == tree->number)
    {
        return true;
    }

    // Recursive cases: search the only branch where it could be
    if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else
    {
        return search(tree->right, number);
    }

}

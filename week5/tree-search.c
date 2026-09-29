#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/cs50.h"

// Data type definition
typedef struct node{
    int number;
    struct node *left;
    struct node *right;
} node;

// Prototype
bool search(node *tree, int number);
node *insert(node *tree, int number);
void print_tree(node *tree);


int main(void)
{
    node *tree = NULL;
    for (int i = 0; i < 7; i++)
    {
        int n = get_int("Number: ");
        tree = insert(tree, n);
    }

    printf("Numbers is order: \n");
    print_tree(tree);
    return 0;
}

node *insert(node *tree, int number)
{
    // Base case: position empty
    if (tree == NULL)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            fprintf(stderr, "Error: not enough memory!");
            return NULL;
        }

        new->number = number;
        new->left = NULL;
        new->right = NULL;
        return new;
    }

    // recursive case
    if (number < tree->number)
    {
        tree->left = insert(tree->left, number);
    }
    else
    {
        tree->right = insert(tree->right, number);
    }
    return tree;
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

// Prototype, before main
void print_tree(node *tree)
{
    if (tree == NULL)
    {
        printf("NULL!");
        return;
    }
    print_tree(tree->left);
    printf("%i\n", tree->number);
    print_tree(tree->right);
}
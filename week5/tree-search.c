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
void unload(node *tree);
node *delete_node(node *tree, int number);


int main(void)
{
    node *tree = NULL;
    for (int i = 0; i < 7; i++)
    {
        int n = get_int("Number: ");
        tree = insert(tree, n);
    }

    printf("Numbers in order: \n");
    print_tree(tree);

    if (search(tree, get_int("If this number exists: ")))
    {
        printf("YES!\n");
    }
    else
    {
        printf("NO!\n");
    }

    unload(tree);
    return 0;
}

// simple insert fuction
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

// Binary search on the tree
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

// Print the tree
void print_tree(node *tree)
{
    // base case
    if (tree == NULL)
    {
        return;
    }
    // recursive part
    print_tree(tree->left);
    printf("%i\n", tree->number);
    print_tree(tree->right);
}

void unload(node *tree)
{
    // Base case
    if (tree == NULL)
    {
        return;
    }
    // Recursive case
    unload(tree->left);
    unload(tree->right);
    free(tree);
}

// Deletation
node *delete_node(node *tree, int number)
{
    if (tree == NULL)
    {
        return NULL;
    }
    // Base case
    if (number == tree->number)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }
        if (tree->left == NULL && tree->right != NULL)
        {
            node *tmp = tree;
            tree = tree->right;
            free(tmp);
            return tree;
        }
        if (tree->right == NULL && tree->left != NULL)
        {
            node *tmp = tree;
            tree = tree->left;
            free(tmp);
            return tree;
        }
        if (tree->right != NULL && tree->left != NULL)
        {
            node *tmp = tree;
            tree->right->left = tree->left;
            tree = tree->right;
            free(tmp);
            return tree;
        }
    }

    // Recursive case
    if (number < tree->number)
    {
        tree->left = delete_node(tree->left, number);
    }
    else
    {
        tree->right = delete_node(tree->right, number);
    }
    return tree;
}

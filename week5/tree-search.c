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
node *left_balance(node *tree);
node *right_balance(node *tree);



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

    int d = get_int("Number to delete: ");

    if (!search(tree, d))
    {
        printf("Number not found!\n");
    }
    else
    {
        tree = delete_node(tree, d);
        printf("%i deleted!\n", d);
        printf("Numbers in order: \n");
        print_tree(tree);
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
            // node *tmp = tree;
            node *ptr = tree->right;
            while (ptr->left != NULL)
            {
                ptr = ptr->left;
            }
            tree->number = ptr->number;
            tree->right = delete_node(tree->right, ptr->number);
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

// TODO: Let's balance this shit!
// Left balance
node *left_rotation(node *tree)
{
    node *temp = tree;
    tree = tree->right;
    temp->right = tree->left;
    tree->left = temp;
    return tree;
}

// Right balance
node *right_rotation(node *tree)
{

}


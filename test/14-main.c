#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int balance;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->left, 50);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance of %d: %+d\n", root->n, balance);
    return (0);
}

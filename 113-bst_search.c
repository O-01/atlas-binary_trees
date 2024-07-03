#include "binary_trees.h"

/**
 * bst_search - Search a tree for a value
 * @tree: Tree to search
 * @value: value to search for
 * Return: Pointer to node with value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else if (value == tree->n)
		return ((bst_t *)&tree->n);
	return (NULL);
}

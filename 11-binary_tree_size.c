#include "binary_trees.h"

/**
 * binary_tree_size - Function to find size of a tree
 * @tree: Tree to find size of
 * Return: Size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (NULL);
	left = tree->left ? binary_tree_size(tree->left) + 1 : 0;
	right = tree->right ? binary_tree_size(tree->right) + 1 : 0;
	return (left + right);
}

#include "binary_trees.h"

/**
 * binary_tree_size - Function to find size of a tree
 * @tree: Tree to find size of
 * Return: Size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (!tree)
		return (0);
	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size);
}

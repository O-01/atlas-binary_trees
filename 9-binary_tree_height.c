#include "binary_trees.h"

/**
 * binary_tree_height - Function to find height of a tree
 * @tree: Tree to find height of
 * Return: Height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (NULL);
	left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right = tree->right ? binary_tree_height(tree->right) + 1 : 0;
	return (left > right ? left : right);
}

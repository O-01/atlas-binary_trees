#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves in a Tree
 * @tree: Tree to count leaves of
 * Return: Number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);
	leaves += (!tree->left && !tree->right);
	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);
	return (leaves);
}

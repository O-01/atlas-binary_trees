#include "binary_trees.h"

/**
 * binary_tree_depth - Function to find depth of a tree
 * @tree: Tree to find depth of
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (NULL);
	return (tree->parent ? 1 + binary_tree_depth(tree->parent) : 0);
}

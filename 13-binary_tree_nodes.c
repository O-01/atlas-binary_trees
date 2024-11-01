#include "binary_trees.h"

/**
 * binary_tree_nodes - Count number of nodes in Tree with at least one branch
 * @tree: Tree to count nodes of
 * Return: Number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);
	nodes += (tree->left || tree->right);
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	return (nodes);
}

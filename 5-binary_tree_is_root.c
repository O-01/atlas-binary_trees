#include "binary_trees.h"

/**
 * binary_tree_is_root - verifies if node is a root within binary tree
 * @node: object node within binary tree
 * Return: 1 if node is root, 0 upon NULL node or not root
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (!node->parent ? 1 : 0);
}

#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds Uncle node of a node
 * @node: node to find uncle of
 * Return: Uncle Node or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
/**
 * binary_tree_sibling - Finds the sibling of a Node
 * @node: node to find sibling of
 * Return: Sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}

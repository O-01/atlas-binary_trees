#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node in a tree
 * @parent: Pointer to parent node to add node to
 * @value: value on new node
 * Return: Pointer to new node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = calloc(1, sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

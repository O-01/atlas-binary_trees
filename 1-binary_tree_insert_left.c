#include "binary_trees.h"

/**
 * binary_tree_insert_left - adds a left child to a parent node
 * @parent: parent node to add to
 * @value: value of new nnode
 * Return: Pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (parent->left)
		new_node->left = parent->left,
		parent->left->parent = new_node;
	parent->left = new_node;
	return (new_node);
}

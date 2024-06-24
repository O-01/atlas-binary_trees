#include "binary_trees.h"

/**
 * binary_tree_insert_left - adds a left child to a parent node
 * @parent: parent node to add to
 * @value: value of new nnode
 * Return: Pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	new_node->n = value;
	new_node->parent = parent;
	parent->left = new_node;
	return (new_node);
}

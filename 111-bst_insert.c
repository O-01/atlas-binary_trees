#include "binary_trees.h"

/**
 * bst_insert - inserts a value in an BST Tree
 * @tree: double pointer to root node of BST tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *add = NULL;

	if (!*tree)
		return (*tree = (binary_tree_node(NULL, value)));
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			add = (binary_tree_node(NULL, value));
			add->parent = *tree, (*tree)->left = add;
			return (add);
		}
		else
			add = bst_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			add = (binary_tree_node(NULL, value));
			add->parent = *tree, (*tree)->right = add;
			return (add);
		}
		else
			add = bst_insert(&(*tree)->right, value);
	}
	else
		return (NULL);
	return (add);
}

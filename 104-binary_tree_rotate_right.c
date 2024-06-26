#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on binary tree
 * @tree: root node of tree to be right-rotated
 * Return: pointer to new root node of tree following right-rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (!tree)
		return (NULL);
	tmp = tree->left;
	tmp->parent = tree->parent;
	tree->left = tmp->right;
	if (tmp->right)
		tmp->right->parent = tree;
	tmp->right = tree;
	tree->parent = tmp;

	return (tmp);
}

#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on binary tree
 * @tree: root node of tree to be left-rotated
 * Return: pointer to new root node of tree following left-rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (!tree)
		return (NULL);
	tmp = tree->right;
	tmp->parent = tree->parent;
	tree->right = tmp->left;
	tmp->left = tree;
	tree->parent = tmp;
	return (tmp);
}

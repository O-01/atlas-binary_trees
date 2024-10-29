#include "binary_trees.h"

/**
 * binary_tree_delete - delete input binary tree
 * @tree: object binary tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	if (tree->left)
		binary_tree_delete(tree->left);
	if (tree->right)
		binary_tree_delete(tree->right);
	free(tree), tree = NULL;
}

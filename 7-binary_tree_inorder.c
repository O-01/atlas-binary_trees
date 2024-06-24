#include "binary_trees.h"

/**
 * binary_tree_inorder - print binary tree elements using inorder traversal
 * @tree: object tree
 * @func: function to be called at each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}

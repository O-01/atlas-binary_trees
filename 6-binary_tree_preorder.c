#include "binary_trees.h"

/**
 * binary_tree_preorder - print binary tree elements using preorder traversal
 * @tree: object tree
 * @func: function to be called at each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

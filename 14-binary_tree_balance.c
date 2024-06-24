#include "binary_trees.h"

int tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measure balance factor of binary tree
 * @tree: object tree
 * Return: balance factor value, 0 upon NULL tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * tree_height - Function to find height of a tree
 * @tree: Tree to find height of
 * Return: Height of tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	left = tree->left ? tree_height(tree->left) + 1 : 0;
	right = tree->right ? tree_height(tree->right) + 1 : 0;
	return (left > right ? left : right);
}

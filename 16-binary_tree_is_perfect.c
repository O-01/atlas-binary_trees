#include "binary_trees.h"

int tree_height(const binary_tree_t *tree);
int tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - verifies perfect status of binary tree
 * @tree: object tree
 * Return: 1 upon perfect, 0 upon NULL tree or upon non-perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree || !tree_is_full(tree->left) || !tree_is_full(tree->right))
		return (0);
	return (tree_height(tree->left) == tree_height(tree->right));
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

/**
 * tree_is_full - verifies if binary tree is full
 * @tree: object tree
 * Return: 1 upon full, 0 upon NULL tree or if tree has 1 node
 */
int tree_is_full(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (tree_is_full(tree->left) * tree_is_full(tree->right));
}

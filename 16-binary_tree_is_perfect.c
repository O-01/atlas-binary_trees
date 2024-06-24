#include "binary_trees.h"

int perfect_recursion(const binary_tree_t *tree, size_t depth, size_t level);
size_t tree_depth(const binary_tree_t *tree);
int tree_balance(const binary_tree_t *tree);
int tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - verifies perfect status of binary tree
 * @tree: object tree
 * Return: 1 upon perfect, 0 upon NULL tree or upon non-perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (perfect_recursion(tree, tree_depth(tree), 0));
}

/**
 * perfect_recursion - verifies input binary tree for perfection recursively
 * @tree: object tree
 * @depth: depth of input tree
 * @level: level of node
 * Return: 1 upon perfect, 0 upon NULL tree or upon non-perfect
 */
int perfect_recursion(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree_balance(tree))
		return (0);
	if (!tree->left && !tree->right)
		return (depth = level + 1);
	return (perfect_recursion(tree->left, depth, level + 1) &&
			perfect_recursion(tree->right, depth, level + 1));
}

/**
 * tree_depth - Function to find depth of a tree
 * @tree: Tree to find depth of
 * Return: depth of tree
 */
size_t tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree->parent ? 1 + tree_depth(tree->parent) : 0);
}

/**
 * tree_balance - measure balance factor of binary tree
 * @tree: object tree
 * Return: balance factor value, 0 upon NULL tree
 */
int tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_height(tree->left) - tree_height(tree->right));
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
	left = tree->left || tree ? tree_height(tree->left) + 1 : 0;
	right = tree->right || tree ? tree_height(tree->right) + 1 : 0;
	return (left > right ? left : right);
}

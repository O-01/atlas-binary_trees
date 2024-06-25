#include "binary_trees.h"

int tree_height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree);
int max_value(const binary_tree_t *tree);
int min_value(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Function to test if a tree is an AVL tree
 * @tree: Tree to test
 * Return: 1 if tree is AVL, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);

	height += tree_height(tree->left);
	height -= tree_height(tree->right);
	if (height < -1 || height > 1)
		return (0);

	if (!is_bst(tree))
		return (0);

	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);
	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
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

/**
 * is_bst - Function for checking if a tree is a BST
 * @tree: Tree to check
 * Return: 1 if tree is BST, 0 if not
 */
int is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if ((tree->left && max_value(tree->left) > tree->n) ||
		(tree->right && min_value(tree->right) < tree->n))
		return (0);
	if (tree->parent &&
		((tree == tree->parent->right &&
			tree->left && tree->left->n < tree->parent->n) ||
		(tree == tree->parent->left &&
			tree->right && tree->right->n > tree->parent->n)))
		return (0);

	if (!is_bst(tree->left) || !is_bst(tree->right))
		return (0);
	return (1);
}

/**
 * max_value- finds the highest value in Tree
 * @tree: Tree to check
 * Return: Highest value
 */
int max_value(const binary_tree_t *tree)
{
	int left = 0, right = 0, max = 0;

	if (!tree)
		return (INT_MIN);
	left = max_value(tree->left);
	right = max_value(tree->right);

	max = left > right ? left : right;
	return (max < tree->n ? tree->n : max);
}

/**
 * min_value- finds the min value in Tree
 * @tree: Tree to check
 * Return: min value
 */
int min_value(const binary_tree_t *tree)
{
	int left = 0, right = 0, min = 0;

	if (!tree)
		return (INT_MAX);
	left = min_value(tree->left);
	right = min_value(tree->right);

	min = left < right ? left : right;
	return (min > tree->n ? tree->n : min);
}

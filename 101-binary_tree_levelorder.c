#include "binary_trees.h"

void current_level(const binary_tree_t *tree, int level, void (*func)(int));
static int tree_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 *                          traversal, calling func on each level's nodes
 *                          successively
 * @tree: pointer to root node of tree to traverse
 * @func: pointer to function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int iter, height = tree_height(tree);

	if (!tree)
		return;
	for (iter = 1; iter <= height; ++iter)
		current_level(tree, iter, func);
}

/**
 * current_level - calls func on nodes of current level
 * @tree: pointer to root node of object tree
 * @level: current level
 * @func: pointer to function to be called
 */
void current_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else
		current_level(tree->left, level - 1, func),
		current_level(tree->right, level - 1, func);
}

/**
 * tree_height - Function to find height of a tree
 * @tree: Tree to find height of
 * Return: Height of tree
 */
static int tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	left = tree->left || tree ? tree_height(tree->left) + 1 : 0;
	right = tree->right || tree ? tree_height(tree->right) + 1 : 0;
	return (left > right ? left : right);
}

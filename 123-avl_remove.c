#include "binary_trees.h"

avl_t *find_heir(avl_t *node);
static avl_t *do_balance(avl_t *tree, int value);

/**
 * avl_remove - Removes a node with specified value from tree
 * @root: Root of tree
 * @value: value to search for
 * Return: Root of tree after rebalance
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value == root->n)
	{
		if (!root->left && !root->right)
		{
			if (root->parent)
				do_balance(root->parent, root->parent->n);
			free(root);
			return (NULL);
		}
		else if (!root->right && root->left)
		{
			root->left->parent = root->parent, tmp = root->left;
			free(root), root = NULL;
			if (tmp->parent)
				do_balance(tmp->parent, tmp->parent->n);
			return (do_balance(tmp, tmp->n));
		}
		else if (!root->left && root->right)
		{
			root->right->parent = root->parent, tmp = root->right;
			free(root), root = NULL;
			if (tmp->parent)
				do_balance(tmp->parent, tmp->parent->n);
			return (do_balance(tmp, tmp->n));
		}
		else if (root->right && root->left)
		{
			tmp = find_heir(root->right);
			root->n = tmp->n, avl_remove(tmp, tmp->n);
			if (root->parent)
				do_balance(root->parent, root->parent->n);
			return (do_balance(root, root->n));
		}
	}
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	if (value > root->n)
		root->right = avl_remove(root->right, value);
	return (do_balance(root, root->n));
}

/**
 * find_heir - Finds the InOrder successor of a node
 * @node: node to check
 * Return: successor node
 */
avl_t *find_heir(avl_t *node)
{
	avl_t *tmp = NULL;
	static int flag;

	if (!node->left && !node->right && !flag)
	{
		node->parent->right = NULL;
		return (node);
	}
	if (!node->left && node->right)
	{
		node = binary_tree_rotate_left(node), tmp = node->left, free(node);
		flag = 0;
		return (tmp);
	}
	else if (!node->left)
	{
		node->parent->left = NULL;
		flag = 0;
		return (node);
	}
	flag = 1;
	return (find_heir(node->left));
}

/**
 * do_balance - balance binary search tree appropriately, if necessary
 * @tree: tree to be checked and balanced
 * @value: value as reference for determining rotation
 * Return: pointer to rotated tree upon disbalance, otherwise pointer to tree
 */
static avl_t *do_balance(avl_t *tree, int value)
{
	int balance = binary_tree_balance(tree);

	if (balance > 1 && value < tree->left->n)
		return (binary_tree_rotate_right(tree));
	if (balance < -1 && value > tree->right->n)
		return (binary_tree_rotate_left(tree));
	if (balance > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}

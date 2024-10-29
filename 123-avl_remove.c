#include "binary_trees.h"

static avl_t *find_heir(avl_t *node);
static avl_t *do_balance(avl_t *tree);

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
			if (root->parent && root == root->parent->left)
				root->parent->left = NULL;
			else if (root->parent && root == root->parent->right)
				root->parent->right = NULL;
			free(root), root = NULL;
			return (NULL);
		}
		else if (!root->right && root->left)
		{
			root->left->parent = root->parent, tmp = root->left;
			free(root), root = NULL;
			return (do_balance(tmp));
		}
		else if (!root->left && root->right)
		{
			root->right->parent = root->parent, tmp = root->right;
			free(root), root = NULL;
			return (do_balance(tmp));
		}
		else if (root->right && root->left)
		{
			tmp = find_heir(root->right);
			root->n = tmp->n, avl_remove(tmp, tmp->n);
			return (do_balance(root));
		}
	}
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	if (value > root->n)
		root->right = avl_remove(root->right, value);
	return (do_balance(root));
}

/**
 * find_heir - Finds the InOrder successor of a node
 * @node: node to check
 * Return: successor node
 */
static avl_t *find_heir(avl_t *node)
{
	avl_t *tmp = NULL;
	static int flag;

	if (!node->left && !node->right && !flag)
	{
		node->parent->right = NULL;
		return (node);
	}
	if (!node->left && node->right && !flag)
	{
		if (node->parent)
			node->parent->right = node->right;
		node = binary_tree_rotate_left(node), tmp = node->left;
		return (tmp);
	}
	if (!node->left && node->right && flag)
	{
		if (node->parent)
			node->parent->right = node->right;
		node = binary_tree_rotate_left(node), tmp = node->left;
		flag = 0;
		return (tmp);
	}
	else if (!node->left && flag)
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
 * Return: pointer to rotated tree upon disbalance, otherwise pointer to tree
 */
static avl_t *do_balance(avl_t *tree)
{
	int balance = binary_tree_balance(tree), l_bal = 0, r_bal = 0;

	if (balance > 1)
	{
		l_bal = binary_tree_balance(tree->left);
		if (l_bal >= 0)
			return (binary_tree_rotate_right(tree));
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	else if (balance < -1)
	{
		r_bal = binary_tree_balance(tree->right);
		if (r_bal <= 0)
			return (binary_tree_rotate_left(tree));
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}

#include "binary_trees.h"

static bst_t *find_heir(bst_t *node);

/**
 * bst_remove - Removes a node with specified value from tree
 * @root: Root of tree
 * @value: value to search for
 * Return: Root of tree after rebalance
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

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
			return (tmp);
		}
		else if (!root->left && root->right)
		{
			root->right->parent = root->parent, tmp = root->right;
			free(root), root = NULL;
			return (tmp);
		}
		else if (root->right && root->left)
		{
			tmp = find_heir(root->right);
			root->n = tmp->n, bst_remove(tmp, tmp->n);
			return (root);
		}
	}
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	if (value > root->n)
		root->right = bst_remove(root->right, value);
	return (root);
}

/**
 * find_heir - Finds the InOrder successor of a node
 * @node: node to check
 * Return: successor node
 */
static bst_t *find_heir(bst_t *node)
{
	bst_t *tmp = NULL;
	static int flag;

	if (!node->left && !node->right && !flag)
	{
		node->parent->right = NULL;
		return (node);
	}
	if (!node->left && node->right && !flag)
	{
		if (node->parent)
			node->parent->right = node->right, node->right->parent = node->parent;
		return (node);
	}
	if (!node->left && node->right && flag)
	{
		if (node->parent)
			node->parent->right = node->right, node->right->parent = node->parent;
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

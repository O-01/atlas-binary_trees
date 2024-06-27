#include "binary_trees.h"

static avl_t *do_balance(avl_t *tree, int value);

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to root node of AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *add = NULL;

	if (!*tree)
	{
		*tree = (binary_tree_node(NULL, value));
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			add = (binary_tree_node(NULL, value));
			add->parent = *tree, (*tree)->left = add;
			return (add);
		}
		else
			add = avl_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			add = (binary_tree_node(NULL, value));
			add->parent = *tree, (*tree)->right = add;
			return (add);
		}
		else
			add = avl_insert(&(*tree)->right, value);
	}
	else
		return (*tree);
	*tree = do_balance(*tree, value);
	return (add);
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

#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds AVL tree from sorted array
 * @array: pointer to first element of sorted array to be converted
 * @size: number of elements in array
 * Return: pointer to root node of created AVL tree, NULL upon failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int mid = (size - 1) / 2;
	avl_t *node = binary_tree_node(NULL, array[mid]);
	avl_t *node_l = NULL, *node_r = NULL;

	if (!array || !size)
		return (NULL);
	node_l = sorted_array_to_avl(array, mid);
	node_r = sorted_array_to_avl(&array[mid + 1], size - mid - 1);
	if (node_l)
		node_l->parent = node;
	if (node_r)
		node_r->parent = node;
	node->left = node_l, node->right = node_r;
	return (node);
}

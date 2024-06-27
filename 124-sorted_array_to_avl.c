#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds AVL tree from sorted array
 * @array: pointer to first element of sorted array to be converted
 * @size: number of elements in array
 * Return: pointer to root node of created AVL tree, NULL upon failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int mid = size / 2;
	avl_t *node = binary_tree_node(NULL, array[mid]);

	if (!array || !size || !node)
		return (NULL);
	node->left = sorted_array_to_avl(array, mid - 1);
	node->right = sorted_array_to_avl(&array[mid + 1], size - mid - 1);
	return (node);
}

#include "binary_trees.h"

/**
 * array_to_avl - builds AVL tree from array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 * Return: pointer to root node of created AVL tree, NULL upon failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t iter = 0;
	avl_t *root = NULL;

	if (!array)
		return (NULL);
	if (!root)
		root = binary_tree_node(NULL, array[iter]), ++iter;
	for (; iter < size; ++iter)
		if (!avl_insert(&root, array[iter]))
			return (NULL);
	return (root);
}

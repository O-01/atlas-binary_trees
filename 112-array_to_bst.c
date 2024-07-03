#include "binary_trees.h"

/**
 * array_to_bst - builds BST tree from array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 * Return: pointer to root node of created BST tree, NULL upon failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t iter = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	if (!root)
		root = binary_tree_node(NULL, array[iter]), iter++;

	for (; iter < size; iter++)
		if (!bst_insert(&root, array[iter]))
			return (NULL);

	return (root);
}

#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/* Our own functions */
void binary_tree_print(const binary_tree_t *tree);
avl_t *array_to_avl(int *array, size_t size);
void binary_tree_delete(binary_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	avl_t *root;
	int array[] = {
		98, 110, 43, 56, 2, 78, 123, 76, 234
	};
	size_t size = sizeof(array) / sizeof(array[0]);

	root = array_to_avl(array, size);
	binary_tree_print(root);

	root = avl_remove(root, 98);
	binary_tree_print(root);
	root = avl_remove(root, 110);
	binary_tree_print(root);
	root = avl_remove(root, 123);
	binary_tree_print(root);

	binary_tree_delete(root);
	return (0);
}

#include "binary_trees.h"

/**
 * binary_tree_node - builds an AVL tree from an array
 *
 * @parent: The array to be printed
 * @n: Size of the array
 * Return: binary tree on success, NULL on failure
 */
avl_t *binary_tree_node(avl_t *parent, size_t n)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}

/**
 * insert_node_AVL - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @parent: the parent of the new node
 * @start: the first element array index to eval
 * @end: the last elemnt array index to eval
 *
 * Return: binary tree on success, NULL on failure
 */
avl_t *insert_node_avl(int *array, size_t start, size_t end,
			avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	if (mid != start)
		root->left = insert_node_avl(array, start, mid - 1, root);

	if (mid != end)
		root->right = insert_node_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @size: Size of the array
 * Return: AVL binary tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);

	root = insert_node_avl(array, 0, size - 1, NULL);
	return (root);
}

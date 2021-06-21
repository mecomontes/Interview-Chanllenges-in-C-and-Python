#include "search.h"

/**
 * check_next_list -  searches for a value
 *
 * @node: is a pointer to the next list to search in
 * @value: is the value to search for
 *
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *check_next_list(skiplist_t *node, int value)
{
	for (; node; node = node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
	}
	return (NULL);
}

/**
 * linear_skip -  searches for a value in a sorted skip int list
 *
 * @list: is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 *
 * Return: pointer first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *node2, *node3;

	if (!list)
		return (NULL);
	node = list;
	while (node)
	{
		if (node->express == NULL)
		{
			node2 = node->express;
			for (node3 = list; node3; node3 = node3->next)
				if (node3->next == NULL)
				{
					printf("Value found between indexes [%lu] and [%lu]\n",
					       node->index, node3->index);
					break;
				}
			break;
		}
		if (node->express->n >= value)
		{
			node2 = node->express;
			printf("Value checked at index [%lu] = [%d]\n", node2->index, node2->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
			       node->index, node2->index);
			break;
		}
		node = node->express;
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	}

	return (check_next_list(node, value));
}

#include "binary_trees.h"

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value, value_aux;
	heap_t *aux;

	if (!root || !*root)
		return (0);
	aux = *root;
	value = aux->n;
	if (!aux->left && !aux->right && !aux->parent)
	{
		free(aux);
		return (value);
	}
	while (aux->left || aux->right)
	{
		if (aux->left && aux->right)
		{
			if (!aux->right || aux->left->n > aux->right->n)
			{
				value_aux = aux->n;
				aux->n = aux->left->n;
				aux->left->n = value_aux;
				aux = aux->left;
			}
			else if (aux->left->n < aux->right->n)
			{
				value_aux = aux->n;
				aux->n = aux->right->n;
				aux->right->n = value_aux;
				aux = aux->right;

			}
		}
	}
	return (value);
}

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - prints all elements of a listint_t list
 * @head: pointer to head of list
 * @number: the numbre to introduce in the list
 * Return: address of the new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		while (current->next != NULL && current->next->n < new->n)
		{
			current = current->next;
		}
		new->next = current->next;
		current->next = new;
	}
	return (new);
}

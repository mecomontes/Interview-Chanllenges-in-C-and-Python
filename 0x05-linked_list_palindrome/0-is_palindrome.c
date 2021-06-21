#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - reverse a list
 * @head: pointer to the header list
 */
void reverse(listint_t **head)
{
	listint_t *current = *head;
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

/**
 * middleList - move the pointer to the middle
 * @head: pointer to the header
 * Return: structure pointer since the middle
 */
listint_t *middleList(listint_t **head)
{
	listint_t *slow = *head;
	listint_t *fast = *head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

/**
 * compareLists - compare if is a palindrome list
 * @head: pointer to the fist num
 * @middle: pointer to the middle of the list
 * Return: 0 if not or 1 if it is
 */
int compareLists(listint_t **head, listint_t *middle)
{
	while (middle != NULL)
	{
		if (middle->n != (*head)->n)
			return (0);
		*head = (*head)->next;
		middle = middle->next;
	}
	return (1);
}

/**
 * is_palindrome - know if is a palindrome
 * @head: word or sentence
 * Return: 0 if not or 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *middle;

	if ((*head) == NULL)
		return (1);

	middle = middleList(head);
	reverse(&middle);
	if ((compareLists(head, middle)) == 1)
		return (1);
	return (0);
}

#include "lists.h"

/**
 * locateloop - check the code for Holberton School students.
 * @head_p: pointer to a node in the list
 * @fast_p: pointer to a node in the list
 * Return: poibter where the loop start
 */
listint_t *locateloop(listint_t *head_p, listint_t *fast_p)
{
	while (head_p != fast_p)
	{
		head_p = head_p->next;
		fast_p = fast_p->next;
	}
	return (head_p);
}

/**
 * find_listint_loop - finds the loop in a linked list.
 *
 * @head: is the direction of the first node of the list
 * Return: the address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p, *fast_p;

	if (!head)
		return (0);

	slow_p = head->next;
	fast_p = head->next->next;
	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			return (locateloop(head, fast_p));
	}
	return (0);
}

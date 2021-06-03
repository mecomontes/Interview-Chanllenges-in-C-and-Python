#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*Singly Linked List*/
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/*Task Functions*/
listint_t *find_listint_loop(listint_t *head);
listint_t *find_listint_loop(listint_t *head);
size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

#endif /* _LIST_H_ */

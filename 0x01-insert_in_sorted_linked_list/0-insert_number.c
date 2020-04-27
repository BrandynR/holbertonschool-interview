#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert new node in a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new node, NULL if fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *prev;
	listint_t *current;

	current = *head;
	prev = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (current->next != NULL)
		{
			/* Quit when found a higher number or end of list */
			if (current->n > number)
				break;
			else
			{
				/* Go to next node */
				prev = current;
				current = current->next;
			}
		}
		if (current->n < number)
		{
			/* Insert at end of list */
			new->next = NULL;
			current->next = new;
		}
		else if (current == *head)
		{
			/* Insert at beginning of list */
			new->next = current;
			*head = new;
		}
		else
		{
			/* Insert in middle of list */
			new->next = current;
			prev->next = new;
		}
	}
	return (new);
}

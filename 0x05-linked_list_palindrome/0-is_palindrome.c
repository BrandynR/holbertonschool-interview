#include "lists.h"

/**
 * is_palindrome - function in C that checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the linked_list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int count = 0, c, numbers[1000000];
	listint_t *temp;


	if (*head == NULL)
		return (1);
	temp = *head;
	while (temp)
	{
		numbers[count] = temp->n;
		temp = temp->next;
		count++;
	}
	count--;
	for (c = 0; c <= count / 2; c++)
	{
		if (numbers[c] != numbers[count - c])
			return (0);
	}
	return (1);
}

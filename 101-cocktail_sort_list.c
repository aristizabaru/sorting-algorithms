#include "sort.h"

/**
 * cocktail_sort_list - sorts an array of integers in ascending order
 * using the Cocktail shaker sort
 * @list: doubly linked list head
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;

	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}

/**
 * swap - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

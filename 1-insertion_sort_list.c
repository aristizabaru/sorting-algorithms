#include "sort.h"
#include <unistd.h>

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort algorithm
 * 
 * @list: Head to the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node, *next_swap;

	/* check list */
	if (list == NULL || *list == NULL)
		return;
	swap_node = (*list)->next;
	while (swap_node != NULL)
	{
		next_swap = swap_node->next;
		while (swap_node->prev != NULL && swap_node->prev->n > swap_node->n)
		{
			swap_node->prev->next = swap_node->next;
			if (swap_node->next != NULL)
				swap_node->next->prev = swap_node->prev;
			swap_node->next = swap_node->prev;
			swap_node->prev = swap_node->next->prev;
			swap_node->next->prev = swap_node;
			if (swap_node->prev == NULL)
				*list = swap_node;
			else
				swap_node->prev->next = swap_node;
			print_list(*list);
		}
		swap_node = next_swap;
	}
}
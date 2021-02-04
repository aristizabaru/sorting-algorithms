#include "deck.h"

/**
 * sort_deck - sort deck of cards
 * @deck: head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	/* check list */
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	sort_values(deck);
	sort_figures(deck);
}

/**
 * sort_figures - sort figures of a card deck
 * @deck: head of the deck
 */
void sort_figures(deck_node_t **deck)
{
	deck_node_t *sorted = *deck;
	deck_node_t *unsorted = sorted->next;
	deck_node_t *temp = NULL;

	while (sorted && unsorted)
	{
		if (sorted->card->kind > unsorted->card->kind)
		{
			temp = sorted->prev;
			while (temp && unsorted->card->kind < temp->card->kind)
				temp = temp->prev;
			if (temp)
			{
				sorted->next = unsorted->next;
				if (unsorted->next)
					unsorted->next->prev = sorted;
				unsorted->next = temp->next;
				unsorted->prev = temp;
				unsorted->next->prev = unsorted;
				temp->next = unsorted;
			}
			else
			{
				sorted->next = unsorted->next;
				if (unsorted->next)
					unsorted->next->prev = sorted;
				unsorted->next = *deck;
				unsorted->prev = NULL;
				(*deck)->prev = unsorted;
				*deck = unsorted;
			}
			unsorted = sorted->next;
		}
		else
		{
			sorted = sorted->next;
			if (sorted && sorted->next)
				unsorted = sorted->next;
		}
	}
}

/**
 * sort_values - sort values of a card deck
 * @deck: head of the deck
 */
void sort_values(deck_node_t **deck)
{
	deck_node_t *sorted = *deck;
	deck_node_t *unsorted = sorted->next;
	deck_node_t *temp = NULL;

	while (sorted && unsorted)
	{
		if (get_val(sorted->card->value) > get_val(unsorted->card->value))
		{
			temp = sorted->prev;
			while (temp && get_val(unsorted->card->value) < get_val(temp->card->value))
				temp = temp->prev;
			if (temp)
			{
				sorted->next = unsorted->next;
				if (unsorted->next)
					unsorted->next->prev = sorted;
				unsorted->next = temp->next;
				unsorted->prev = temp;
				unsorted->next->prev = unsorted;
				temp->next = unsorted;
			}
			else
			{
				sorted->next = unsorted->next;
				if (unsorted->next)
					unsorted->next->prev = sorted;
				unsorted->next = *deck;
				unsorted->prev = NULL;
				(*deck)->prev = unsorted;
				*deck = unsorted;
			}
			unsorted = sorted->next;
		}
		else
		{
			sorted = sorted->next;
			if (sorted && sorted->next)
				unsorted = sorted->next;
		}
	}
}

/**
 * get_val - gets the relative value of a card from it's string value
 * @str: string value of the card
 *
 * Return: relative value of the card (0 through 12)
 */
int get_val(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			   "10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
		if (strcmp(str, array[i]) == 0)
			return (i);
	return (0);
}

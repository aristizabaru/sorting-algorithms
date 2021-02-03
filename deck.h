#ifndef __DECK_H__
#define __DECK_H__
/* libraries */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* structs and enums */
/**
 * enum kind_e - Order of kind
 * @SPADE: spade kind is num 0
 * @HEART: heart kind is num 1
 * @CLUB: club kind is num 2
 * @DIAMOND: diamond kind is num 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
/* prototypes */
void sort_deck(deck_node_t **deck);
void sort_figures(deck_node_t **deck);
void sort_values(deck_node_t **deck);
int get_val(const char *str);
#endif

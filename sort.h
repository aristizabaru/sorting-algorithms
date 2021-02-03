#ifndef __SORT_H__
#define __SORT_H__

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*estructures*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*prototypes*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size);
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap(listint_t **list, listint_t *node);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int size, int mid, int *temp);
void split(int *array, int size, int *temp);
void heap_sort(int *array, size_t size);
void downheap(int *array, int n, int i);
int max(int *array, int n, int i, int j, int k);
void radix_sort(int *array, size_t size);
int get_max(int a[], int n);
void bitonic_sort(int *array, size_t size);
void recbitonic(int low, int c, int dir, int *array);
void bitonicmerge(int low, int c, int dir, int *array);
void compare(int i, int j, int dir, int *array);
#endif

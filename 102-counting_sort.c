#include "sort.h"

/**
 * counting_sort - sort an array using counting sort algorithm
 * @array: Pointer to array of int
 * @size: Size of the array
 * Description: array must not have negative values in order
 * to work properly
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, i;
	int *count = NULL, *sort = NULL;

	if (array == NULL || size < 2)
		return;
	/* find largest number "k"*/
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	/* create count array with size of k+1*/
	count = malloc(sizeof(int) * k + 1);
	if (count == NULL)
		return;
	for (i = 0; i <= k; i++)
		count[i] = 0;
	/* count keys using count array */
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	/* update count array */
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);
	/* create sort array */
	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		sort[i] = 0;
	/* place values in sort array */
	for (i = (int)size - 1; i >= 0; i--)
		sort[--count[array[i]]] = array[i];
	/* copy sorted values to original array */
	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];
	free(count);
	free(sort);
	count = NULL;
}

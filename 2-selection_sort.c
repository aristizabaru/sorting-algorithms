#include "sort.h"

/**
 * selection_sort - sort an array using selection sort algorithm
 * 
 * @array: Pointer to array of int
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t c_min = NULL;
	size_t c_current = NULL;
	size_t i = 0, j = 0;

	if (array == NULL || size < 2)
		return;
	/* traverse list */
	for (i = 0; i < size - 1; i++)
	{
		/* lock min item */
		c_min = i;
		/* traverse from sorted item */
		for (j = i + 1; j < size; j++)
		{
			/* if new min is found save it */
			if (array[j] < array[c_min])
				c_min = j;
		}
		/* if min is different swap it */
		if (c_min != i)
		{
			c_current = array[i];
			array[i] = array[c_min];
			array[c_min] = c_current;
			print_array(array, size);
		}
	}
}
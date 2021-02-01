#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sort algorithm
 * 
 * @array: Pointer to array of int
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t size_inv = size;
	size_t i = 0, j = 1;
	int temp = 0;
	int swap_flag = 0;

	/* traverse array if it has more than 1 element */
	while (array && size > 1 && i < size)
	{
		j = 1;
		/* compare each element */
		while (j < size_inv)
		{
			/* swap elements */
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				swap_flag = 1;
				print_array(array, size);
			}
			j++;
		}
		/* look for swaps */
		if (swap_flag == 0)
			break;
		/* lock sorted element at the tail */
		size_inv--;
		i++;
	}
}
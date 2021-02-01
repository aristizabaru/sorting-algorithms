#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * shell sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1, temp, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = interval * 3 + 1; interval > 0; interval = interval / 3)
	{
		for (i = interval; i < (int)size; i += 1)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}

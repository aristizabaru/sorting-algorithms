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
	int interval = 1, length = (int)size - 1;
	int valueToInsert, inner, outer;

	if (array == NULL || size < 2)
		return;

	/* calculate interval*/
	while (interval < length / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer = interval; outer < length; outer++)
		{
			/* select value to be inserted */
			valueToInsert = array[outer];
			inner = outer;

			/*shift element towards right*/
			while (inner > interval - 1 && array[inner - interval] >= valueToInsert)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}

			/* insert the number at hole position */
			array[inner] = valueToInsert;
		}

		/* calculate interval*/
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}

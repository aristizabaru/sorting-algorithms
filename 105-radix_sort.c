#include "sort.h"

/**
 * radix_sort - sort an array using radix sort algorithm
 * @array: Pointer to array of int
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, i, pass;

	if (array == NULL || size < 2)
		return;
	/* find max number */
	for (i = 0; i < (int)size; i++)
		if (max < array[i])
			max = array[i];
	/* pass sorting items with LSD */
	for (pass = 1; max / pass > 0; pass *= 10)
	{
		count_sort(array, size, pass);
		print_array(array, size);
	}
}
/**
 * count_sort - bucket count for radix sort
 * @array: Pointer to array of int
 * @n: Size of the array
 * @pass: number of current pass according to digit
 */
void count_sort(int *array, int n, int pass)
{
	int count[10] = {0};
	int i;
	int *b = malloc(sizeof(int) * n);

	if (!b)
		return;
	for (i = 0; i < n; i++)
		b[i] = 0;
	for (i = 0; i < n; i++)
		++count[(array[i] / pass) % 10];
	for (i = 1; i <= n; i++)
		count[i] = count[i] + count[i - 1];
	for (i = n - 1; i >= 0; i--)
		b[--count[(array[i] / pass) % 10]] = array[i];
	for (i = 0; i < n; i++)
		array[i] = b[i];
	free(b);
}

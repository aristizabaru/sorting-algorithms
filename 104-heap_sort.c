#include "sort.h"

/**
 * heap_sort - sort an array using heap sort algorithm
 * @array: Pointer to array of int
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, t;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; i--)
	{
		downheap(array, size, i);
		print_array(array, size);
	}
	for (i = 0; i < (int)size; i++)
	{
		t = array[size - i - 1];
		array[size - i - 1] = array[0];
		array[0] = t;
		downheap(array, size - i - 1, 0);
		print_array(array, size);
	}
}
/**
 * downheap - screate heap
 * @array: Pointer to array of int
 * @n: size
 * @i: index
 */
void downheap(int *array, int n, int i)
{
	int t, j;

	while (1)
	{
		j = max(array, n, i, 2 * i + 1, 2 * i + 2);
		if (j == i)
		{
			break;
		}
		t = array[i];
		array[i] = array[j];
		array[j] = t;
		i = j;
	}
}
/**
 * max - find max numbers
 * @array: Pointer to array of int
 * @n: size
 * @i: index
 * @j: ---
 * @k: ---
 * Return: max value from tree
 */
int max(int *array, int n, int i, int j, int k)
{
	int m = i;

	if (j < n && array[j] > array[m])
	{
		m = j;
	}
	if (k < n && array[k] > array[m])
	{
		m = k;
	}
	return (m);
}

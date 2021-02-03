#include "sort.h"

/**
 * bitonic_sort - sort an array using bitonic sort algorithm
 * @array: Pointer to array of int
 * @size: Size of the array
 * Descritpion: only works on sequenses to the power of two
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	if (array == NULL || size < 2)
		return;
	recbitonic(0, size, up, array);
}

/**
 * recbitonic - create bitonic sequence
 * @low: first index
 * @c: size of array
 * @dir: direction
 * @array: array
 */
void recbitonic(int low, int c, int dir, int *array)
{
	int k;
	int up = 1;
	int down = 0;

	if (c > 1)
	{
		k = c / 2;
		recbitonic(low, k, up, array);
		recbitonic(low + k, k, down, array);
		bitonicmerge(low, c, dir, array);
	}
}
/**
 * bitonicmerge - merge bitonic sequenses
 * @low: first index
 * @c: size of array
 * @dir: direction
 * @array: array
 */
void bitonicmerge(int low, int c, int dir, int *array)
{
	int k, i;

	if (c > 1)
	{
		k = c / 2;
		for (i = low; i < low + k; i++)
			compare(i, i + k, dir, array);
		bitonicmerge(low, k, dir, array);
		bitonicmerge(low + k, k, dir, array);
	}
}
/**
 * compare - merge bitonic sequenses
 * @i: first index
 * @j: size of array
 * @dir: direction
 * @array: array
 */
void compare(int i, int j, int dir, int *array)
{
	int t;

	if (dir == (array[i] > array[j]))
	{
		t = array[i];
		array[i] = array[j];
		array[j] = t;
		print_array(array, j);
	}
}

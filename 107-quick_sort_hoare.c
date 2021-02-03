#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm and the Hoare partition scheme
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quicksort_hoare(int *array, int lo, int hi, int size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition_hoare(array, lo, hi, size);
		quicksort_hoare(array, lo, pivot, size);
		quicksort_hoare(array, pivot + 1, hi, size);
	}
}

/**
 * partition - finds the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
int partition_hoare(int *array, int lo, int hi, int size)
{
	int i, j;
	int swap, pivot;

	pivot = array[lo];
	i = lo - 1;
	j = hi + 1;
	for (;;)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap = array[i];
		array[i] = array[j];
		array[j] = swap;
		print_array(array, size);
	}
}

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
 * quicksort_hoare - sorts a partition of an array of integers
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
 * partition_hoare- finds the partition using the Lomuto scheme
 * @array: array to sort
 * @lo: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
int partition_hoare(int *array, int lo, int hi, int size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

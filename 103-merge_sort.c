#include "sort.h"

/**
 * merge_sort - sort an array using merge sort algorithm
 * @array: Pointer to array of int
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	split(array, size, temp);
	free(temp);
}
/**
 * split - split the array in smaller pieces
 * @array: Pointer to array of int
 * @size: upper bound
 * @temp: target array to merge
 */
void split(int *array, int size, int *temp)
{
	int mid = size / 2;

	if (size < 2)
		return;
	split(array, mid, temp);
	split(array + mid, size - mid, temp);
	merge(array, size, mid, temp);
}
/**
 * merge - merge two arrays to sort them
 * @array: Pointer to array of int
 * @mid: lower bound
 * @size: upper bound
 * @temp: target array to merge
 */
void merge(int *array, int size, int mid, int *temp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	for (i = 0, j = mid, k = 0; k < size; k++)
	{
		temp[k] = j == size		? array[i++]
			  : i == mid		? array[j++]
			  : array[j] < array[i] ? array[j++]
						: array[i++];
	}
	printf("[right]: ");
	print_array(array + mid, size - i);
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	printf("[Done]: ");
	print_array(array, size);
}

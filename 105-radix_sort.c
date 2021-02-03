#include "sort.h"

/**
 * radix_sort - sort an array using radix sort algorithm
 * @a: Pointer to array of int
 * @n: Size of the array
 */
void radix_sort(int *a, size_t n)
{
	int bucket[10][10], bucket_cnt[10];
	int i, j, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = get_max(a, n);
	if (a == NULL || n < 2)
		return;

	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < (int)n; i++)
		{
			r = (a[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = a[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				a[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		print_array(a, n);
	}
}
/**
 * get_max - bucket count for radix sort
 * @a: Pointer to array of int
 * @n: Size of the array
 * Return: max value from array
 */
int get_max(int a[], int n)
{
	int i;
	int max = a[0];

	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return (max);
}

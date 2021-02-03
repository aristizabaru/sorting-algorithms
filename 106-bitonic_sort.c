#include "sort.h"
#define MAX 8
#define SWAP(x, y) \
        t = x;     \
        x = y;     \
        y = t;

/**
 * radix_sort - sort an array using radix sort algorithm
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

/*
 * Generates bitonic sequence by sorting recursively
 * two halves of the array in opposite sorting orders
 * bitonicmerge will merge the resultant data
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
/*
 * Sorts a bitonic sequence in ascending order if dir=1
 * otherwise in descending order
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
/*
 * compare and swap based on dir
 */
void compare(int i, int j, int dir, int *array)
{
        int t;

        if (dir == (array[i] > array[j]))
        {
                SWAP(array[i], array[j]);
                print_array(array, j);
        }
}

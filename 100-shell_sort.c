#include "sort.h"
/**
 * swap - swap two elements @i and @j in an @a
 * @a : array of elements
 * @i : integer number
 * @j : integer number
 *
 * Return : Nothing
 */
void swap(int a[], int i, int j)
{
	int temp = 0;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

/**
 * shell_sort - in-place comparison sorting algorithm by selecting
 * pairs of elements in @array far apart from each other and placing them
 * into their correct positions in the subarray and then
 * progressively reducing the gap while sorting them respectively
 * Knuth sequence := 'n + 1 = n * 3 + 1'
 *
 * @array : array of elements
 * @size : size of the array
 *
 * Return : Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, index, pos;

	if (array == NULL)
		exit(EXIT_FAILURE);

	while (gap < (size / 3))
		gap = (gap * 3) + 1;

	while (gap >= 1)
	{
		for (index = gap; index < size; index++)
		{
			for (pos = index; pos >= gap; pos -= gap)
			{
				if (array[pos] < array[pos - gap])
					swap(array, pos, (pos - gap));
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}

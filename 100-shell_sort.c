#include "sort.h"
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
	size_t gap = 1, index = 0, pos = 0;
	int val = 0;

	if (array == NULL)
		exit(EXIT_FAILURE);
	if (size == 1)
		return;

	while (gap < (size / 3))
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (index = gap; index < size; index++)
		{
			val = array[index];
			pos = index;

			while (pos >= gap && array[pos - gap] > val)
			{
				array[pos] = array[pos - gap];
				pos -= gap;
			}
			if (pos != index)
				array[pos] = val;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}

#include "sort.h"
/**
 * swap - swap values of two elements @i and @j
 * @i : pointer to an integer number
 * @j : pointer to an integer number
 *
 * Return : Nothing
 */
void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * get_partition_index - Get the partition index
 * @array : array of elements
 * @low : left most index position
 * @high : right most index position
 * @size : size of the array
 *
 * Return: position of the pivot in the @array
 */
int get_partition_index(int *array, int low, int high, size_t size)
{
	int index = low, pivot = array[high], pi = low - 1;

	for (; index < high; index++)
	{
		if (array[index] < pivot)
		{
			pi++;
			if (index != pi)
			{
				swap(&array[pi], &array[index]);
				print_array(array, size);
			}
		}
	}
	pi++;
	if (array[high] < array[pi])
	{
		swap(&array[pi], &array[high]);
		print_array(array, size);
	}
	return (pi);
}

/**
 * partition - partition @array of @size into sub-arrays
 * using @low as lower bound and @high as higher bound
 * @array : array of elements
 * @low : left most index position
 * @high : right most index position
 * @size : size of the array
 *
 * Return : Nothing
 */
void partition(int *array, int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		pi = get_partition_index(array, low, high, size);
		if (pi >= 0)
		{
			partition(array, low, pi - 1, size);
			partition(array, pi + 1, high, size);
		}
	}
}

/**
 * quick_sort - in-place comparison sorting algorithm for sorting
 * integer numbers in @array of @size in correct positions by partitioning
 * array into 2 sub-arrays according to whether less or greater than pivot
 * then sorting the sub-arrays recursively in-place by swapping them
 * <-- Lomuto partition scheme -->
 *
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	char *best_case = "O(nlog(n))", *average_case = "O(nlog(n))";
	char *worst_case = "O(n^2)";
	FILE *fp = fopen("3-O", "w");

	if (fp == NULL || array == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	partition(array, 0, size - 1, size);

	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

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
 * partition - partition @array into sub-arrays
 * using @left as lower bound and @right as higher bound
 * @array : array of elements
 * @left : left index position
 * @right : right index position
 * @size : size of the array
 *
 * Return : pivot index
 */
void partition(int *array, int left, int right, int size)
{
	int index, mid, pivot, low = left;

	mid = (left + right) / 2;
	pivot = array[mid];
	if (left >= right)
		return;
	for (index = left; index <= right; index++)
	{
		if (array[index] < pivot && array[index] < array[low])
		{
			swap(array, low++, index);
			print_array(array, size);
		}
		else if (array[index] < pivot && index > mid)
		{
			swap(array, mid, index);
			print_array(array, size);
		}
	}
	partition(array, left, mid, size);
	partition(array, mid + 1, right, size);
}

/**
 * quick_sort - in-place comparison sorting algorithm for sorting
 * integer numbers in @array of @size in correct positions by partitioning
 * array into 2 sub-arrays according to whether less or greater than pivot
 * then sorting the sub-arrays recursively in-place by swapping them
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int left = 0, right = size - 1;
	char *best_case = "n * log n", *average_case = "n * logn";
	char *worst_case = "n * n";
	FILE *fp = fopen("3-O", "w");

	if (fp == NULL || array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	partition(array, left, right, size);

	fprintf(fp, "O(%s)\nO(%s)\nO(%s)\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

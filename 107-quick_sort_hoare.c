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
 * partition - partition @array of @size into sub-arrays
 * using @left as lower bound and @right as higher bound
 * @array : array of elements
 * @left : left most index position
 * @right : right most index position
 * @size : size of the array
 *
 * Return : Nothing
 */
void partition(int *array, int left, int right, int size)
{
	int NOTSORTED = 1, pivot, mid, low, high;

	if (left >= right)
		return;
	mid = (left + right) / 2;
	pivot = array[mid];

	while (NOTSORTED)
	{
		low = left - 1;
		high = right + 1;
		do {
			low++;
		} while (array[low] < pivot);
		do {
			high--;
		} while (array[high] > pivot);
		if (low >= high)
			break;
		swap(array, low, high);
		print_array(array, size);
	}
	mid = high;
	partition(array, mid + 1, right, size);
	partition(array, left, mid, size);
}

/**
 * quick_sort_hoare - in-place comparison sorting algorithm for sorting
 * integer numbers in @array of @size in correct positions by partitioning
 * array into 2 sub-arrays according to whether less or greater than pivot
 * then sorting the sub-arrays recursively in-place by swapping them
 * <-- Hoare partition scheme -->
 *
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	int left = 0, right = size - 1;
	char *best_case = "O(nlogn)", *average_case = "O(nlogn)";
	char *worst_case = "O(n^2)";
	FILE *fp = fopen("107-O", "w");

	if (fp == NULL || array == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	partition(array, left, right, size);

	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

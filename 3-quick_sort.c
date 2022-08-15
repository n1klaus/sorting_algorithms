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
	int index = 0, left = 0, mid = 0, right = size;
	char *best_case = "n * log n", *average_case = "n * logn";
	char *worst_case = "n * n";
	FILE *fp = fopen("3-O", "w");

	if (fp == NULL || array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/* do nothing if array contains less than two elements */
	if (left >= right || left < 0 || size <= 2)
	{
		return;
	}
	/* swap elements mid and left temporarily */
	swap(array, left, (left + right)/ 2);
	/* save the previously mid; now left element as mid for future use */
	mid = left;
	/* scan the mid+1 to right partition for elements smaller than mid */
	for (index = left + 1; index <= right; index++)
	{
		if (array[index] < array[left])
		{
			swap(array, ++mid, index);
			print_array(array, size);
		}
	}
	/* swap elements mid and left back; with left having the smallest value for range mid+1 to right */
	swap(array, left, mid);
	/* sort elements from left to mid-1 partition */
	quick_sort(&array[left], mid - 1);
	/* sort elements from mid+1 to right partition */
	quick_sort(&array[mid + 1], right - mid);
	fprintf(fp, "O(%s)\nO(%s)\nO(%s)\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

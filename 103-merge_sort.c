#include "sort.h"
/**
 * print_subarray - Prints a array of integers
 * @array : The array to be printed
 * @left : left-most index of @array
 * @right : right-most index of @array
 *
 * Return: Nothing
 */
void print_subarray(int *array, int left, int right)
{
	int i = left, counter = 0;

	while (array != NULL && i < right)
	{
		if (counter > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
		++counter;
	}
	printf("\n");
}

/**
 * copy_array - copy @src to @dest
 * @src : souce array
 * @left : left-most index of @src
 * @right : right-most index of @src
 * @dest : destination array
 *
 * Return: 0 if successfull, otherwise 1
 */
int copy_array(int *src, int left, int right, int *dest)
{
	int index = left;

	for (; index < right; index++)
		dest[index] = src[index];
	if (index == (right - 1) && src[right - 1] == dest[right - 1])
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/**
 * merge_array - merge left and right sub-arrays from @src into @dest
 * @src : source array
 * @left : left-most index of @src
 * @mid : middle index of @src
 * @right : right-most index of @src
 * @dest : destination array
 *
 * Return : Nothing
 */
void merge_array(int *src, int left, int mid, int right, int *dest)
{
	int index, loc = left, pivot = mid;

	for (index = left; index < right; index++)
	{
		if (loc < mid && (pivot >= right || src[loc] <= src[pivot]))
		{
			dest[index] = src[loc++];
		}
		else
		{
			dest[index] = src[pivot++];
		}
	}
}

/**
 * split_array - split @original into 2 sub-arrays of almost
 * equal size and sort both sub-arrays into @copy
 * and then merge both sorted sub-arrays back into @original
 * @original : original array
 * @left : left-most index of @src
 * @right : right-most index of @src
 * @copy : destination array
 *
 * Return : Nothing
 */
void split_array(int *copy, int left, int right, int *original)
{
	int mid = 0;

	if (right - left <= 1)
		return;

	mid = (right + left) / 2;
	split_array(original, left, mid, copy);
	split_array(original, mid, right, copy);
	fprintf(stdout, "Merging...\n");
	fprintf(stdout, "[left]: ");
	print_subarray(copy, left, mid);
	fprintf(stdout, "[right]: ");
	print_subarray(copy, mid, right);
	merge_array(copy, left, mid, right, original);
	fprintf(stdout, "[Done]: ");
	print_subarray(original, left, right);
}

/**
 * merge_sort - comparison sorting algorithm for recursively splitting
 * unsorted @array of @size into sub-arrays until each sub-array
 * contains only one element and sub-array is size 1, then repeatedly
 * merge the sub-arrays to produce the final sorted array
 * <-- Top-down Implementation -->
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int left = 0, right = size;
	char *best_case = "O(nlogn)", *average_case = "O(nlogn)";
	char *worst_case = "O(nlogn)";
	int *new_array = (int *)malloc(sizeof(int) * size);
	FILE *fp = fopen("103-O", "w");

	if (fp == NULL || array == NULL || new_array == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	copy_array(array, left, right, new_array);
	split_array(new_array, left, right, array);

	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	free(new_array);
	fclose(fp);
}

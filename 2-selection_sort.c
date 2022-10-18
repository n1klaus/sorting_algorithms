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
 * selection_sort - in-place comparison sorting algorithm for swapping
 * smaller integer numbers in @array of @size in correct positions by
 * managing a sorted sublist on the left and an unsorted sublist on the right
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t index = 0, min = 0, pos = 0;
	char *best_case = "O(n^2)", *average_case = "O(n^2)",
		*worst_case = "O(n^2)";
	FILE *fp = fopen("2-O", "w");

	if (fp == NULL || array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (size > 1)
	{
		for (index = 0; index < size - 1; index++)
		{
			min = index;
			for (pos = index + 1; pos < size; pos++)
			{
				if (array[pos] < array[min])
					min = pos;
			}
			if (min != index)
			{
				swap(&array[index], &array[min]);
				print_array(array, size);
			}
		}
	}
	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

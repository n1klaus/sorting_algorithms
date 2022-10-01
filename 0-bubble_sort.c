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
 * bubble_sort - comparison sort algorithm for adjacent
 * integer numbers in @array of @size swapping and
 * putting largest integer number at the top of the list
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	bool swapped = false;
	char *best_case = "O(n)";
	char *average_case = "O(n^2)";
	char *worst_case = "O(n^2)";
	FILE *fp = fopen("0-O", "w");

	if (fp == NULL || array == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (size > 1)
	{
		for (i = 0; i < size; i++)
		{
			swapped = false;
			for (j = 0; j < size - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					print_array(array, size);
					swapped = true;
				}
			}
			if (!swapped)
				break;
		}
	}
	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

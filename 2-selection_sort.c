#include "sort.h"
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
	ssize_t temp = 0;
	char *best_case = "n", *average_case = "n * n", *worst_case = "n * n";
	FILE *fp = fopen("2-O", "w");

	if (fp == NULL || array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (size > 1)
	{
		for (index = 0; index < size; index++)
		{
			min = index;
			for (pos = index + 1; pos < size; pos++)
			{
				if (array[pos] < array[min])
					min = pos;
			}
			if (array[min] < array[index])
			{
				temp = array[index];
				array[index] = array[min];
				array[min] = temp;
				print_array(array, size);
			}
		}
	}
	fprintf(fp, "O(%s)\nO(%s)\nO(%s)\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

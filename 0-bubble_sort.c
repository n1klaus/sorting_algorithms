#include "sort.h"
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
	size_t index = 0, count = size - 1;
	ssize_t temp = 0;
	char *best_case = "n", *average_case = "n^2", *worst_case = "n^2";
	FILE *fp = fopen("0-O", "w");

	if (fp == NULL || array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (size > 1)
	{
		while (count--)
		{
			for (index = 0; index < size; index++)
			{
				if (array[index] < array[index - 1])
				{
					temp = array[index];
					array[index] = array[index - 1];
					array[index - 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
	fprintf(fp, "O(%s)\nO(%s)\nO(%s)\n", best_case, average_case,
		worst_case);
	fclose(fp);
}

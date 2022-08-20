#include "sort.h"
/**
 * counting_sort - integer sorting algorithm for a collection of objects
 * according to keys as index to @array by counting number of objects
 * with distinct keys and applying prefix sum on those counts to determine
 * the positions of each key value in the output sequence
 * @array : array of elements
 * @size : size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	size_t index = 0, counter = 0, loc = 0, range = 100;
	char *best_case = "O(nlogn)", *average_case = "O(n)";
	char *worst_case = "O(n)";
	int *count = (int *)malloc(sizeof(int) * range);
	int *output = (int *)malloc(sizeof(int) * size);
	FILE *fp = fopen("102-O", "w");

	if (fp == NULL || array == NULL)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	for (index = 0; index < range; index++)
		count[index] = 0;
	for (index = 0; index < size; ++index)
	{
		counter = array[index];
		++count[counter];
	}

	for (index = 1; index < range; index++)
		count[index] += count[index - 1];
	print_array(count, range);

	for (index = size - 1; (int)index >= 0; --index)
	{
		counter = array[index];
		loc = count[counter];
		output[loc - 1] = array[index];
		--count[counter];
	}
	for (index = 0; index < size; ++index)
		array[index] = output[index];

	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	free(count);
	free(output);
	fclose(fp);
}

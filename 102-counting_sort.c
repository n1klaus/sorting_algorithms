#include "sort.h"
/**
 * max - get the maximum number in the array
 * @array: array of elements
 * @size: size of the array
 *
 * Return: maximum number in a list of numbers
 */
size_t max(int *array, size_t size)
{
	size_t index = 0, max = 0;

	for (; index < size; index++)
		if (array[index] > (int)max)
			max = array[index];
	return (max);
}

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
	size_t index = 0, counter = 0, loc = 0, range = (max(array, size) + 1);
	char *best_case = "O(n+k)", *average_case = "O(n+k)";
	char *worst_case = "O(n+k)";
	int *count = (int *)malloc(sizeof(int) * range), count_ref = 0;
	int *output = (int *)malloc(sizeof(int) * size);
	FILE *fp = fopen("102-O", "w");

	if (fp && size > 1)
	{
		for (index = 0; index < range; index++)
			count[index] = 0;

		for (index = 0; index < size; ++index)
		{
			if (index < size - 1 && array[index] > array[index + 1])
				count_ref += 1;
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
	}
	fprintf(fp, "%s\n%s\n%s\n", best_case, average_case,
		worst_case);
	free(count);
	free(output);
	fclose(fp);
}

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

#include "search_algos.h"

/**
 * jump_search - Jump search algorithm
 * @array: Integer array to be searched
 * @size: size of the array
 * @value: value to search for
 * Return: Always EXIT_SUCCESS.
 */
int jump_search(int *array, size_t size, int value)
{
	int index, m, k, previous;

	if (array == NULL || size == 0)
		return (-1);

	m = (int)sqrt((double)size);
	k = 0;
	previous = index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		k++;
		previous = index;
		index = k * m;
	} while (index < (int)size && array[index] < value);

	printf("Value found between indexes [%d] and [%d]\n", previous, index);

	for (; previous <= index && previous < (int)size; previous++)
	{
		printf("Value checked array[%d] = [%d]\n", previous, array[previous]);
		if (array[previous] == value)
			return (previous);
	}

	return (-1);
}

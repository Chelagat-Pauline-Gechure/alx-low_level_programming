#include "search_algos.h"

/**
 * linear_search - Linear search algorithm
 * @array: Integer array to be searched
 * @size: size of the array
 * @value: value to search for
 * Return: Always EXIT_SUCCESS
 */

int linear_search(int *array, size_t size, int value)
{
	size_t value_x;

	if (array == NULL)
	{
		return (-1);
	}

	for (value_x = 0; value_x < size; value_x++)
	{
		printf("Value checked array[%li] = [%i]\n", value_x, array[value_x]);
		if (array[value_x] == value)
		{
			return (value_x);
		}
	}
	return (-1);
}

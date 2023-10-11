#include "search_algos.h"

/**
* binary_search - Binary search algorithm.
 * @array: Integer array to be searched
 * @size: size of the array
 * @value: value to search for
 * Return: index of value is located or -1 if not found.
*/

int binary_search(int *array, size_t size, int value)
{
	size_t x, left, right, middle;

	if (array == NULL || size == 0)
		return (-1);

	left = 0;
	right = size - 1;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (x = left; x < right; x++)
			printf("%d, ", array[x]);
		printf("%d\n", array[x]);

		middle = left + (right - left) / 2;

		if (array[middle] == value)
			return (middle);

		if (array[middle] < value)
			left = middle + 1;
		else
			right = middle - 1;
	}

	return (-1);
}

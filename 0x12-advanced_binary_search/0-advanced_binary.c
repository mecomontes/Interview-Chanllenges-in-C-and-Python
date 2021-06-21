#include "search_algos.h"

/**
 * advanced_binary - search the value into the array
 *
 * @array: pointer first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return:  the index where value is located or -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mitad, index = 0;
	int tmp;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
	if (i == size - 1)
		printf("%d\n", array[i]);
	else
		printf("%d, ", array[i]);
	}

	if (size == 1 && array[0] != value)
		return (-1);
	mitad = (size - 1) / 2;
	if (array[mitad] == value)
	{
		if (array[mitad - 1] < value)
			return (mitad);
	}
	if (array[mitad] < value)
	{
		index += mitad + 1;
		array += mitad + 1;
		if (size % 2 != 0)
			mitad--;
	}
	mitad++;
	tmp = advanced_binary(array, mitad, value);
	if (tmp != -1)
		return (tmp + index);
	return (-1);
}

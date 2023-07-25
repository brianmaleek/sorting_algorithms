#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t x, y, min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}
		if (min != x)
		{
			tmp = array[x];
			array[x] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}

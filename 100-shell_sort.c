#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, y, z, tmp;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (int)size; gap = gap * 3 + 1)
	;

	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (y = gap; y < (int)size; y++)
		{
			tmp = array[y];
			for (z = y; z >= gap && array[z - gap] > tmp; z -= gap)
				array[z] = array[z - gap];
			array[z] = tmp;
		}
		print_array(array, size);
	}
}

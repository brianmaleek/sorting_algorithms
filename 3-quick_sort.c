#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort_helper(array, 0, size - 1, size);
}

/**
 * sort_helper - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @low: lowest index
 * @high: highest index of
 * @size: size of the array
 * Return: void
 */

void sort_helper(int *array, int low, int high, size_t size)
{
	int x;

	if (low < high)
	{
		x = partition(array, low, high, size);
		sort_helper(array, low, x - 1, size);
		sort_helper(array, x + 1, high, size);
	}
}

/**
 * partition - partitions an array of integers in ascending order
 * @array: array to be sorted
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 * Return: void
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1;
	int y, tmp;

	for (y = low; y <= high - 1; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			tmp = array[x];
			array[x] = array[y];
			array[y] = tmp;
			if (x != y)
				print_array(array, size);
		}
	}
	tmp = array[x + 1];
	array[x + 1] = array[high];
	array[high] = tmp;
	if (x + 1 != y)
		print_array(array, size);
	return (x + 1);
}


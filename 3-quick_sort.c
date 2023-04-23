#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending
 *		order using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - implementing lomuto partitioning scheme
 * @array: The array of integers.
 * @size: The size of the array.
 * @f: First element (lower).
 * @s: Second element (higher).
 *
 * Return: The final partition
 */

int lomuto_partition(int *array, size_t size, int f, int s)
{
	int a = f - 1, b = f;
	int pivot = array[s], q_sort = 0;

	for (; b < s; b++)
	{
		if (array[b] < pivot)
		{
			a++;
			if (array[a] != array[b])
			{
				q_sort = array[a];
				array[a] = array[b];
				array[b] = q_sort;
				print_array(array, size);
			}
		}
	}
	if (array[a + 1] != array[s])
	{
		q_sort = array[a + 1];
		array[a + 1] = array[s];
		array[s] = q_sort;
		print_array(array, size);
	}
	return (a + 1);
}

/**
 * lomuto_sort - implementing lomuto sort
 * @array: The array of integers.
 * @size: The size of the array.
 * @f: First element (lower).
 * @s: Second element (higher).
 *
 * Return: void
 */

int lomuto_sort(int *array, size_t size, int f, int s)
{
	int pivot;

	if (f < s)
	{
		pivot = partition(array, size, f, s);
		lomuto_sort(array, size, f, pivot - 1);
		lomuto_sort(array, size, pivot + 1, s);
	}
}

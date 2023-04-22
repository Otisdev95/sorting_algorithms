#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t a = 0, b = 0;
	int bubble = 0;

	if (array == NULL || size == 0)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{

			{
				bubble = array[b + 1];
				array[b + 1] = array[b];
				array[b] = bubble;
				print_array(array, size);
			}
		}
	}
	return (1);
}

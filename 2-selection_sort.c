#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 *		ascending order using the Selection sort algorithm
 * @array: An array to sort.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t a = 0, b = 0, point = 0;
	int s_sort = 0;

	if (array == NULL || size == 0)
		return;

	for (; a < size - 1; a++)
	{
		/* Find nd assume the minimum element */
		point = a;
		for (b = a + 1; b < size; b++)
		{
			/* if array[b] is < then it's the array[point] */
			if (array[b] < array[point])
				point = b;
		}
		if (point != a)
		{
			/* Swap the two elements */
			s_sort = array[a];
			array[a] = array[point];
			array[point] = s_sort;
			print_array(array, size);
		}
	}
}

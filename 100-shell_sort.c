#include "sort.h"

/**
 * swap_int - Swaps two integers in an array.
 * @x: The first integer to be swapped.
 * @y: The next integer to be swapped.
 */

void swap_int(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 *		using the Shell sort algorithm, using the Knuth
 *		sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t point, a, b;

	if (array == NULL || size < 2)
		return;

	for (point = 1; point < (size / 3);)
		point = point * 3 + 1;
	for (; point >= 1; point /= 3)
	{
		for (a = point; a < size; a++)
		{
			b = a;
			while (b >= point && array[b - point] > array[b])
			{
				swap_int(array + b, array + (b - point));
				b -= point;
			}
		}
		print_array(array, size);
	}
}

#include "sort.h"
#include <stdlib.h>

/**
 * swap_root_nodes - Swaps the root nodes.
 * @array: The head to be sorted.
 * @root: The root of the heap.
 * @size: The size of the array.
 * @right: The higher index at the RHS.
 *
 * Return: Nothing
 */

void swap_root_nodes(int *array, size_t root, size_t size, size_t right)
{
	size_t left, mid, temp;
	int aux = 0;

	while ((left = (2 * root + 1)) <= right)
	{
		temp = root;
		mid = left + 1;
		if (array[temp] < array[left])
			temp = left;
		if (mid <= right && array[temp] < array[mid])
			temp = mid;
		if (temp == root)
			return;
		aux = array[root];
		array[root] = array[temp];
		array[temp] = aux;
		print_array(array, size);
		root = temp;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *		using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	size_t right = 0, space = 0;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	for (space = (size - 2) / 2; 1; space--)
	{
		swap_root_nodes(array, space, size - 1, size);
		if (space == 0)
			break;
	}
	right = size - 1;
	while (right > 0)
	{
		temp = array[right];
		array[right] = array[0];
		array[0] = temp;
		print_array(array, size);
		right--;
		swap_root_nodes(array, 0, right, size);
	}
}

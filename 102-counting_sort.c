#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 *		order using the Counting sort algorithm
 * @array: An array  to be sorted.
 * @size: The size of the array to be sorted.
 *
 * Return: Nothing.
 */

void counting_sort(int *array, size_t size)
{
	size_t b, temp, total = 0;
	int a, max;
	int *count = NULL, *sorted = NULL;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);/*Assign malloc for sorted*/
	if (sorted == NULL)
		return;
	for (b = 0, max = 0; b < size; b++)
	{
		sorted[b] = array[b];
		if (array[b] > max)
			max = array[b];
	}
	count = malloc(sizeof(int) * (max + 1));/*Assign malloc for count*/
	if (count == NULL)
	{
		free(sorted);
		return;
	}
	for (a = 0; a <= max; a++)/*Intializing the array count with 0*/
		count[a] = 0;
	/* Commence the array count of the 2nd element */
	for (b = 0; b < size; b++)
		count[array[b]] += 1;
	for (a = 0; a <= max; a++)/* Summing the counts */
	{
		temp = count[a];
		count[a] = total;
		total += temp;
	}
	for (b = 0; b < size; b++)/*Sorting & assigning array with sorted*/
	{
		array[count[sorted[b]]] = sorted[b];
		count[sorted[b]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(sorted);
}

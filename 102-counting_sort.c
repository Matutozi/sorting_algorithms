#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - function that sorts an array using counting algorithm.
  * @array: array to be sorted.
  * @size: length of array.
  * Return: Nothing.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int y = 1;
	int *count_line = NULL, k = 0, z = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; y < size; y++)
	{
		if (array[y] > k)
			k = array[y];
	}

	count_line = malloc(sizeof(int) * (k + 1));
	if (count_line == NULL)
		return;

	for (z = 0; z <= k; z++)
		count_line[z] = 0;
	for (y = 0; y < size; y++)
		count_line[array[y]] += 1;
	for (z = 0; z < k; z++)
	{
		count_line[z + 1] += count_line[z];
		printf("%d, ", count_line[z]);
	}
	count_line[z + 1] += count_line[z];
	printf("%d\n", count_line[z + 1]);
	for (y = 0; y < size; y++)
	{
		y = count_line[array[y]] - 1;
		if (array[y] != array[z])
		{
			k = array[y];
			array[y] = array[z];
			array[z] = k;
		}
	}
	free(count_line);

}

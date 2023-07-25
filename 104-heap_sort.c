#include "sort.h"

/**
 * swap_root - function that swap the root nodes.
 * @array: heap to sort.
 * @root: root of heap.
 * @higr: higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t higr, size_t size)
{
	size_t lowr = 0, midd = 0, temp = 0;
	int aux = 0;

	while ((lowr = (2 * root + 1)) <= higr)
	{
		temp = root;
		midd = lowr + 1;
		if (array[temp] < array[lowr])
			temp = lowr;
		if (midd <= higr && array[temp] < array[midd])
			temp = midd;
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
 * heap_sort - function that sorts an array using heap algorithm.
 * @array: array to be sorted.
 * @size: size of array.
 * Return: None.
 */
void heap_sort(int *array, size_t size)
{
	size_t higr = 0, gap = 0;
	int temp = 0;

		if (array == NULL || size < 2)
			return;

		for (gap = (size - 2) / 2; 1; gap--)
		{
			swap_root(array, gap, size - 1, size);
			if (gap == 0)
				break;
		}

		higr = size - 1;
		while (higr > 0)
	{
		temp = array[higr];
		array[higr] = array[0];
		array[0] = temp;
		print_array(array, size);
		higr--;
		swap_root(array, 0, higr, size);
	}
}

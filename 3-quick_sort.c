#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order by using Quick sort algorithm
 * @array: array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lowr: lower
 * @higr: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lowr, int higr, size_t size)
{
	int i = lowr - 1, j = lowr;
	int pivot1 = array[higr], aux = 0;

	for (; j < higr; j++)
	{
		if (array[j] < pivot1)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[higr])
	{
		aux = array[i + 1];
		array[i + 1] = array[higr];
		array[higr] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_so - quick sort
 * @array: given array
 * @lowr: lower
 * @higr:higher
 * @size: array's size
 * Return: void
 */
void quick_so(int *array, int lowr, int higr, size_t size)
{
	int pivot1;

	if (lowr < higr)
	{
		pivot1 = partition(array, lowr, higr, size);
		quick_so(array, lowr, pivot1 - 1, size);
		quick_so(array, pivot1 + 1, higr, size);
	}
}

#include "sort.h"
/**
 * bubble_sort - sorts an array of data in ascending order
 * @array: unsorted array
 * @size: number of elements in array
 * Return: return sorted array
*/

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, check = 1;

	if (size < 2)
		return;
	while (check != 0)
	{
		check = 0;
		for (i = 0; i < size - 1; i++)
		{
			j = i + 1;
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
				check++;
			}
		}
	}
}

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
	size_t y, z, check_sort = 1;

	if (size < 2)
		return;
	while (check_sort != 0)
	{
		check_sort = 0;
		for (y = 0; y < size - 1; y++)
		{
			z = y + 1;
			if (array[y] > array[z])
			{
				temp = array[y];
				array[y] = array[z];
				array[z] = temp;
				print_array(array, size);
				check_sort++;
			}
		}
	}
}

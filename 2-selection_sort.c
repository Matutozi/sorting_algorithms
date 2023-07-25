#include "sort.h"

/**
 * selection_sort - sorts an array of integer data in ascending order
 * @array: data array
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t j, i, index = 0;
	int temp, current_pos, min;

	if (size < 2)
		return;
	for (j = 0; j < size - 1; j++)
	{
		min = array[j];
		i = j;
		while (i < size)
		{
			current_pos = array[i];
			if (current_pos < min)
			{
				index = i;
				min = array[index];
				i++;
			}
			else
				i++;
		}
		if (index)
		{
			temp = array[j];
			array[j] = min;
			array[index] = temp;
			print_array(array, size);
		}
		index = 0;
	}
}

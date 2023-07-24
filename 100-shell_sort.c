#include "sort.h"

/**
  * shell_sort - function that sorts an array using shell algorithm.
  * @array: array to sort.
  * @size: array length
  * Return: None.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int y = 0, z = 0, gap_sort = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	while (gap_sort < size / 3)
		gap_sort = gap_sort * 3 + 1;

	for (; gap_sort > 0; gap_sort = (gap_sort - 1) / 3)
	{
		for (y = gap_sort; y < size; y++)
		{
			aux = array[y];
			for (z = y; z >= gap_sort && array[z - gap_sort] > aux;
					z -= gap_sort)
			{
				if (array[z] != array[z - gap_sort])
					array[z] = array[z - gap_sort];
			}
			if (array[z] != aux)
				array[z] = aux;

		}
		print_array(array, size);
	}
}

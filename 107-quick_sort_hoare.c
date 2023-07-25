#include "sort.h"
/**
*swap_arr - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap_arr(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current1 = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current1++;
		} while (array[current1] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current1 >= finder)
			return (current1);
		swap_arr(array, current1, finder);
		print_array(array, size);
	}
}
/**
 *quis - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quis(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position1 = 0;

	if (first < last)
	{
		position1 = hoare_partition(array, first, last, size);
		quis(array, first, position1 - 1, size);
		quis(array, position1, last, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quis(array, 0, size - 1, size);
}

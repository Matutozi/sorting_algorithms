#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is a calloc function
 *@ele_no: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int ele_no, unsigned int size)
{
	unsigned int z = 0;
	char *p;

	if (ele_no == 0 || size == 0)
		return ('\0');
	p = malloc(ele_no * size);
	if (*p == '\0')
		return ('\0');
	for (z = 0; z < (ele_no * size); z++)
		p[z] = '\0';
	return (p);
}
/**
 *merge - make a merge
 *@arr: one from start to mid
 *@temp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: first element position
 *@mid: array middle
 *@end: last element position
 **/
void merge(int *arr, int *temp, int start, int mid, int end)
{
	/*  sizes and temp arrays */
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	/* counters */
	int left, right, z = 0;

	array_left = &temp[0];
	array_right = &temp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, z = start;
	/* merging temp arrays into main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[z] = array_left[left], left++;
		else
			arr[z] = array_right[right], right++;
		z++;
	}
	/* merging remaining left array into main array*/
	while (left < size_left)
		arr[z] = array_left[left], left++, z++;
	/* merging remaining right array into main array*/
	while (right < size_right)
		arr[z] = array_right[right], right++, z++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 *mergesort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: array of integers
 *@temp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: fisrt element position
 *@end: last element position
 *Return: void
 */
void mergesort(int *array, int *temp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, temp, start, mid);
		mergesort(array, temp, mid + 1, end);
		merge(array, temp, start, mid, end);
	}
}
/**
 *merge_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: size of the list
 *@array: array of integers
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = _calloc(size, sizeof(int));
	mergesort(array, temp, 0, size - 1);
	free(temp);
}

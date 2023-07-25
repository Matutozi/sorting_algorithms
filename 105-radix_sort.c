#include "sort.h"
#include <stdio.h>
/**
* getMax - utility function that gets maximum value in array
* @arr: array
* @n: size of the array
* Return: array
*/
int getMax(int *arr, int n)
{
	int z, max = arr[0];

	for (z = 1; z < n; z++)
		if (arr[z] > max)
			max = arr[z];
	return (max);
}

/**
* count_sort1 - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void count_sort1(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	/*
	* Change count[i] so that count[i] now contains actual
    * position of this digit in output[]
	*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/*
	* Copy the output array to arr[], so that arr[] now
    * contains sorted numbers according to current digit
	*/
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
	/*print_array(arr, n);*/
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, maximum1 = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (*array == '\0' || size < 2)
		return;

	maximum1 = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (*output == '\0')
		return;
	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; maximum1 / exp > 0; exp *= 10)
	{
		count_sort1(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}

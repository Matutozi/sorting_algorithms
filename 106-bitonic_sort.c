#include "sort.h"
#include <stdio.h>
/**
 * swap_ch - change two values in ascending or descending order
 * @arr: array
 * @item_1: item one
 * @item_2: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap_ch(int arr[], int item_1, int item_2, int order)
{
	int temp;

	if (order == (arr[item_1] > arr[item_2]))
	{
		temp = arr[item_1];
		arr[item_1] = arr[item_2];
		arr[item_2] = temp;
	}
}
/**
 * merge_ele - sort bitonic sequences recursively in both orders
 * @arr: array
 * @lowr: first element
 * @ele_no: elements number
 * @order: 1: ascending order, 0 descending order
 */
void merge_ele(int arr[], int lowr, int ele_no, int order)
{
	int mid, z;

	if (ele_no > 1)
	{
		mid = ele_no / 2;
		for (z = lowr; z < lowr + mid; z++)
			swap_ch(arr, z, z + mid, order);
		merge_ele(arr, lowr, mid, order);
		merge_ele(arr, lowr + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @lowr: first element
 * @ele_no: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int lowr, int ele_no, int order, int size)
{
	int mid;

	if (ele_no > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", ele_no, size);
			print_array(&arr[lowr], ele_no);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", ele_no, size);
			print_array(&arr[lowr], ele_no);
		}
		mid = ele_no / 2;
		bitonicsort(arr, lowr, mid, 1, size);
		bitonicsort(arr, lowr + mid, mid, 0, size);
		merge_ele(arr, lowr, ele_no, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", ele_no, size);
			print_array(&arr[lowr], ele_no);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", ele_no, size);
			print_array(&arr[lowr], ele_no);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}

#include "sort.h"

/**
* swap - function that swaps the position of two numbers
* @a: first parameter
* @b: second parameter
* Return: voidi
*/

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

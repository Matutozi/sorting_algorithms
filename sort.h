#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to previous element of the list
 * @next: Pointer to next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int lowr, int higr, size_t size);
void quick_so(int *array, int lowr, int higr, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void swap_root(int *array, size_t root, size_t higr, size_t size);
void heap_sort(int *array, size_t size);
void swap_ch(int arr[], int item_1, int item_2, int order);
void merge_ele(int arr[], int lowr, int ele_no, int order);
void bitonicsort(int arr[], int lowr, int ele_no, int order, int size);
void bitonic_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);
void *_calloc(unsigned int ele_no, unsigned int size);
void merge(int *arr, int *temp, int start, int mid, int end);
void mergesort(int *array, int *temp, int start, int end);
void merge_sort(int *array, size_t size);


#endif /*_SORT_H */

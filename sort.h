#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in node
 * @prev: Pointer to previous element of list
 * @next: Pointer to next element of list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
int partition(int *array, int lowr, int higr, size_t size);
void quick_so(int *array, int lowr, int higr, size_t size);
void shell_sort(int *array, size_t size);

#endif /*_SORT_H */

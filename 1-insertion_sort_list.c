#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 *                       of integers in ascending order using Insertion
 *                       sort algorithm
 * @list: the  doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node_1 = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node_1 = *list;
	node_1 = node_1->next;
	while (node_1)
	{
		while (node_1->prev && node_1->n < (node_1->prev)->n)
		{
			temp = node_1;
			if (node_1->next)
				(node_1->next)->prev = temp->prev;
			(node_1->prev)->next = temp->next;
			node_1 = node_1->prev;
			temp->prev = node_1->prev;
			temp->next = node_1;
			if (node_1->prev)
				(node_1->prev)->next = temp;
			node_1->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			node_1 = node_1->prev;
		}
		node_1 = node_1->next;
	}

}

#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swap node for the previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current1 = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current1->next;
	if (current1->next)
		current1->next->prev = back;
	current1->next = back;
	current1->prev = back->prev;
	back->prev = current1;
	if (current1->prev)
		current1->prev->next = current1;
	else
		*list = current1;
	return (current1);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node1;
	int swap_done = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node1 = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (node1->next)
		{
			if (node1->n > node1->next->n)
			{
				node1 = swap_node(node1->next, list);
				swap_done = 1;
				print_list(*list);
			}
			node1 = node1->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (node1->prev)
		{
			if (node1->n < node1->prev->n)
			{
				node1 = swap_node(node1, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				node1 = node1->prev;
		}
	}
}

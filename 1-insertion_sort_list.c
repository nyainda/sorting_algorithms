#include "sort.h"
void swap_nodes(listint_t **a, listint_t **b);
/**
 * insertion_sort_list - sort list in ascending order
 * @list: head of list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *curr = NULL, *prev = NULL;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;

		while (temp) /* iterate to end of list */
		{
			curr = temp;
			prev = temp->prev;

			/* if values are not ascending */
			while (prev && curr->n < prev->n)
			{
				swap_nodes(&prev, &curr);
				if (prev == *list) /* if curr now list head */
					*list = curr;
				print_list(*list);
				/* if (curr->prev != NULL) if not at head of list */
				prev = curr->prev;
			}
			temp = temp->next;
		}
	}
}
/**
 * swap_nodes - swap two nodes
 * @a: left node
 * @b: right node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
	(*a)->next = (*b)->next;
	(*b)->prev = (*a)->prev;
	if ((*b)->next)
		(*b)->next->prev = (*a);
	if ((*a)->prev)
		(*a)->prev->next = (*b);
	(*b)->next = (*a);
	(*a)->prev = (*b);
}

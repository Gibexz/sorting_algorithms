#include "sort.h"

listint_t *swapList(listint_t *px, listint_t *cx, listint_t **list);

/**
 * insertion_sort_list - insertion sort for doubly linked list
 *
 * @list: doubly linked-list to sort
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *prevos, *current;

	if ( list == NULL || *list == NULL || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		prevos = current->prev;

		while ((temp->prev) && (prevos->n > temp->n))
		{
			current = swapList(prevos, temp, list);
			print_list(*list);
			if (temp->prev == NULL)
				break;
			prevos = temp->prev;
		}
		current = current->next;
	}
}

/**
 * swapList - swap to doubly linked list elements
 * @px: i.e previous element
 * @cx: i.e current element
 *
 * Return: pointer to swapped element (of higher value).
 */
listint_t *swapList(listint_t *px, listint_t *cx, listint_t **list)
{
	if (px->prev)
		(px->prev)->next = cx;
	else
		*list = cx, cx->prev = NULL;
	if ((cx->next))
		(cx->next)->prev = px;
	cx->prev = px->prev;
	px->prev = cx;
	px->next = cx->next;
	cx->next = px;
	return (px);
}

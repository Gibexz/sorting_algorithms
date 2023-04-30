#include "sort.h"

/**
 * swap - swaps two nodes
 * @head: head of the list
 * @node1: first node to sort
 * @node2: second node to sort
 */
void swapNodes(listint_t **head, listint_t *nodeA, listint_t *nodeB)
{
	listint_t *prev, *next;

	prev = nodeA->prev;
	next = nodeB->next;

	if (prev != NULL)
		prev->next = nodeB;
	else
		*head = nodeB;
	nodeA->prev = nodeB;
	nodeA->next = next;
	nodeB->prev = prev;
	nodeB->next = nodeA;
	if (next)
		next->prev = nodeA;
}
/**
 * cocktail_sort_list - sorts a list using the cocktail-sort algorithm
 * @list: the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (list == NULL || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swapNodes(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swapNodes(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}

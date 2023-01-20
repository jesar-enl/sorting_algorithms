#include "sort.h"

/**
 * len_list - find the length of the list
 *
 * @h: the lsit
 * Return: length
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort - function to sort the list using insertion mode
 *
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL;
	listint_t *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;

	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;
			two->next = four;

			if (four)
				four->prev = two;

			three->prev = one;
			three->next = two;
			if (one)
				one->next = three;
			else
				*list = three;

			two->prev = three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
		{
			current = current->next;
		}
	}
}

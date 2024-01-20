#include "sort.h"
/**
 * _swap - swap two nodes
 *
 * @f_node: first node
 * @s_node: second node
 */
void _swap(listint_t *f_node, listint_t *s_node)
{
	if (f_node->prev)
		f_node->prev->next = s_node;
	if (s_node->next)
		s_node->next->prev = f_node;

	f_node->next = s_node->next;
	s_node->prev = f_node->prev;
	f_node->prev = s_node;
	s_node->next = f_node;
}

/**
 * insertion_sort_list - insertion sort algorithm.
 * @list: list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxt, *current;

	if (!list || !*list || !(*list)->next)
		return;

	nxt = (*list)->next;
	while (nxt)
	{
		current = nxt;
		nxt = nxt->next;
		while (current && current->prev)
		{
			if (current->prev->n > current->n)
			{
				_swap(current->prev, current);
				if (!current->prev)
					*list = current;
				print_list((const listint_t *)*list);
			}
			else
				current = current->prev;
		}
	}
}

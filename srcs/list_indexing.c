/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:23:49 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/04 19:13:09 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static void nodes_swap(t_node *a, t_node *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

static void list_sorting(t_list *list)
{
    int swapped;
    t_node *ptr1;
    t_node *lptr;
	
	lptr = NULL;
	swapped = 1;
    if (list->head == NULL)
        return;
    while (swapped)
	{
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) { 
                nodes_swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void	list_indexing(t_list **stack_a, t_list **copy)
{
	t_node	*head;
	t_node	*head_copy;
	int		i;

	list_sorting(*copy);
	head = (*stack_a)->head;
	head_copy = (*copy)->head;
	while (head && head_copy)
	{
		i = 1;
		while (head_copy && head)
		{
			if (head_copy->value == head->value)
			{
				head->index = i;
				head_copy = (*copy)->head;
				break ;
			}
			i++;
			head_copy = head_copy->next;
		}
		head = head->next;
	}
	l_free(copy);
}

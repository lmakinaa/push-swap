/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:00:06 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:48:39 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	where_is_index_zero(t_list **stack_a)
{
	t_node	*head_a;

	list_init_pos(stack_a);
	head_a = (*stack_a)->head;
	while (head_a)
	{
		if (head_a->index == 1)
			return (head_a->pos);
		head_a = head_a->next;
	}
	return (INT_MAX);
}

void	fix_stack(t_list **stack_a, int argc)
{
	t_node	*head_a;
	int		beg_pos;
	
	head_a = (*stack_a)->head;
	beg_pos = where_is_index_zero(stack_a);
	if (beg_pos > argc / 2)
		while ((*stack_a)->head->index != 1)
			rrx(*stack_a, "rra");
	else
		while ((*stack_a)->head->index != 1)
			rx(*stack_a, "ra");
}

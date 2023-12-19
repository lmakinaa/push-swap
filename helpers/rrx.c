/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:25:48 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 17:26:09 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	rr(t_list *stack_a, t_list *stack_b)
{
	rx(stack_a);
	rx(stack_b);
}

void	rrx(t_list *stack_x)
{
	t_node	*tmp;

	if (l_len(stack_x) > 1)
	{
		tmp = stack_x->head;
		while (tmp->next->next)
			tmp = tmp->next;
		stack_x->tail = tmp;
		tmp = tmp->next;
		tmp->next = stack_x->head;
		stack_x->head = tmp;
		stack_x->tail->next = NULL;
	}
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}

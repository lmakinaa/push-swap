/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:24:39 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 17:25:21 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	sx(t_list *stack_x)
{
	int		tmp;

	if (l_len(stack_x) > 1)
	{
		tmp = stack_x->head->value;
		stack_x->head->value = stack_x->head->next->value;
		stack_x->head->next->value = tmp;
	}
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sx(stack_a);
	sx(stack_b);
}

void	px(t_list *stack_x1, t_list *stack_x2)
{
	t_node	*tmp;

	if (l_len(stack_x2) > 0)
	{
		tmp = stack_x2->head;
		stack_x2->head = stack_x2->head->next;
		tmp->next = stack_x1->head;
		stack_x1->head = tmp;
	}
}

void	rx(t_list *stack_x)
{
	t_node	*tmp;

	if (l_len(stack_x) > 1)
	{
		tmp = stack_x->head;
		stack_x->head = stack_x->head->next;
		tmp->next = NULL;
		l_addback(stack_x, tmp);
	}
}

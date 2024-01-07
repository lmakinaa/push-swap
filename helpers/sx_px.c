/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:24:39 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:07:50 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	sx(t_list *stack_x, char *print)
{
	int		tmp;

	if (l_len(stack_x) > 1)
	{
		tmp = stack_x->head->value;
		stack_x->head->value = stack_x->head->next->value;
		stack_x->head->next->value = tmp;
	}
	if (print)
		ft_putendl_fd(print, 1);
}

void	ss(t_list *stack_a, t_list *stack_b, char *print)
{
	sx(stack_a, NULL);
	sx(stack_b, NULL);
	if (print)
		ft_putendl_fd(print, 1);
}

void	px(t_list *stack_x1, t_list *stack_x2, char *print)
{
	t_node	*tmp;

	if (l_len(stack_x2) > 0)
	{
		tmp = stack_x2->head;
		stack_x2->head = stack_x2->head->next;
		tmp->next = stack_x1->head;
		stack_x1->head = tmp;
		if (!stack_x1->tail)
			stack_x1->tail = stack_x1->head;
	}
	if (print)
		ft_putendl_fd(print, 1);
}

void	rx(t_list *stack_x, char *print)
{
	t_node	*tmp;

	if (l_len(stack_x) > 1)
	{
		tmp = stack_x->head;
		stack_x->head = stack_x->head->next;
		tmp->next = NULL;
		l_addback(stack_x, tmp);
	}
	if (print)
		ft_putendl_fd(print, 1);
}

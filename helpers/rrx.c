/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:25:48 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/02 16:02:03 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	rr(t_list *stack_a, t_list *stack_b, char *print)
{
	rx(stack_a, NULL);
	rx(stack_b, NULL);
	if (print)
		ft_putendl_fd(print, 1);
}

void	rrx(t_list *stack_x, char *print)
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
	if (print)
		ft_putendl_fd(print, 1);
}

void	rrr(t_list *stack_a, t_list *stack_b, char *print)
{
	rrx(stack_a, NULL);
	rrx(stack_b, NULL);
	if (print)
		ft_putendl_fd(print, 1);
}

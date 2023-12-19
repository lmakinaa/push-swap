/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:10:17 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 16:08:03 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void l_display(t_list *list)
{
	t_node	*after_head;
	int		i;

	if (!list)
	{
		ft_printf("The list is empty!\n");
		return ;
	}
	if (!list->head)
	{
		ft_printf("The list have no head!\n");
		return ;
	}
	if (!list->tail)
	{
		ft_printf("The list have no tail!\n");
		return ;
	}
	ft_printf("The head's content-->[%d]\n", list->head->value);
	after_head = list->head->next;
	i = 2;
	if (after_head)
	{
		while (after_head->next)
		{
			ft_printf("[%d]-->[%d]\n", i, after_head->value);
			after_head = after_head->next;
			i++;
		}
	}
	ft_printf("The tail's content-->[%d]\n", list->tail->value);
}
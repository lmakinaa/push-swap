/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_display.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:10:17 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:51:26 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	l_display(t_list *list)
{
	t_node	*after_head;
	int		i;

	if (!list)
		return (ft_printf("The list is empty!\n"));
	if (!list->head)
		return (ft_printf("No head!\n"));
	if (!list->tail)
		return (ft_printf("No tail!\n"));
	ft_printf("The head's content-->[%d]\n", list->head->value);
	after_head = list->head->next;
	i = 2;
	if (after_head)
	{
		while (after_head->next)
		{
			ft_printf("[%d]-->[%d]", after_head->pos, after_head->value);
			after_head = after_head->next;
			i++;
		}
	}
	return (ft_printf("The tail's content-->[%d]\n", list->tail->value));
}

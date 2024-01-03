/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_before.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:22:33 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/29 18:21:31 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	l_addbefore(t_list *list, t_node *node1, t_node *node2)
{
	t_node	*tmp;
	t_node	*tmp1;
	t_node	*head;

	if (!list || !list->head)
	{
		ft_printf("Invalide list!\n");
		return ;
	}
	head = list->head;
	while (head && head->next)
	{
		tmp = head;
		if (tmp->next == node1)
		{
			tmp1 = tmp->next;
			tmp->next = node2;
			node2->next = tmp1;
			return ;
		}
	}
}

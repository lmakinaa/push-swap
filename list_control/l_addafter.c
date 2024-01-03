/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_addafter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:14:32 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/29 18:19:49 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	l_addafter(t_list *list, t_node *node1, t_node *node2)
{
	t_node	*tmp;
	t_node	*tmp1;
	t_node	*head;

	if (!list || !list->head || !node1 || !node2)
	{
		ft_printf("Invalide list or node!\n");
		return ;
	}
	head = list->head;
	while (head)
	{
		tmp = head;
		if (tmp == node1)
		{
			tmp1 = tmp->next;
			tmp->next = node2;
			node2->next = tmp1;
			return ;
		}
		head = head->next;
	}
}

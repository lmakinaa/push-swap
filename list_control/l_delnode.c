/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_delnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:46:05 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/29 18:21:47 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	l_delnode(t_list *list, t_node *node)
{
	t_node	*tmp;

	tmp = list->head;
	if (tmp == node)
	{
		list->head = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = node->next;
	free(node);
}

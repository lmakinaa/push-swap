/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_addfront.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:07:46 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 16:07:49 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void l_addfront(t_list *list, t_node *node)
{
	if (!node || !list)
		return ;
	if (!list->head)
	{
		list->head = node;
		list->tail = node;
		return ;
	}
	node->next = list->head;
	list->head = node;
}
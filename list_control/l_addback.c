/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_addback.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:05 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 16:07:43 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void l_addback(t_list *list, t_node *node)
{
	if (!node || !list)
		return ;
	if (!list->tail && !list->head)
	{
		list->tail = node;
		list->head = node;
		return ;
	}
	list->tail->next = node;
	list->tail = node;
}

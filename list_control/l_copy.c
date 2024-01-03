/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:52:02 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/03 18:52:46 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/list_control.h"

t_list	*l_copy(t_list *list)
{
	t_list	*new_list;
	t_node	*node;

	new_list = c_list();
	node = list->head;
	while (node)
	{
		l_addback(new_list, c_node(node->value));
		node = node->next;
	}
	return (new_list);
}

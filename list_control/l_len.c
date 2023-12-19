/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:19 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 17:45:02 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

size_t	l_len(t_list *list)
{
	size_t len;
	t_node *tmp;

	if (!list->head)
		return (0);
	len = 0;
	tmp = list->head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

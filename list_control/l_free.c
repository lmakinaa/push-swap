/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:15:18 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/30 16:07:35 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	l_free(t_list **list)
{
	t_node	*head;
	t_node	*tmp;

	if (*list && !((*list)->head))
		return (free(*list));
	if (!*list || !(*list)->head)
	{
		ft_printf("Invalide list!\n");
		return ;
	}
	head = (*list)->head;
	while (head && head->next)
	{
		tmp = head;
		free(tmp);
		head = head->next;
	}
	free(head);
	free(*list);
}

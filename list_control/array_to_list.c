/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:00:35 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/31 18:24:41 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

t_list	*array_to_list(int *array, int len)
{
	t_list	*list;
	int		i;

	i = 0;
	list = c_list();
	while (i < len)
	{
		l_addback(list, c_node(array[i]));
		i++;
	}
	return (list);
}

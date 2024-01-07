/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:09:01 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:29:12 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

t_node	*c_node(int value)
{
	t_node	*res;

	res = malloc(sizeof(t_node));
	if (!res)
		return (NULL);
	res->value = value;
	res->pos = -1;
	res->index = 0;
	res->move_cost_a = -1;
	res->move_cost_b = -1;
	res->next = NULL;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:09:01 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/29 18:19:12 by ijaija           ###   ########.fr       */
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
	res->next = NULL;
	return (res);
}

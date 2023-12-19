/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:06:03 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 16:07:33 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

t_list *c_list(void)
{
	t_list *res;

	if (!(res = malloc(sizeof(t_list))))
		return (NULL);
	res->head = NULL;
	res->tail = NULL;
	return (res);
}
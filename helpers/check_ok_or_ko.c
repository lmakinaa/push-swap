/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ok_or_ko.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:40:16 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/19 16:55:14 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	check_ok_or_ko(t_list *stack_a, size_t n_args)
{
	t_node	*tmp;

	if (l_len(stack_a) != n_args)
	{
		ft_printf("KO\n");
		exit(0);
	}
	tmp = stack_a->head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
		{
			ft_printf("KO\n");
			exit(0);
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}

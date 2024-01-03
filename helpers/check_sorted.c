/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:07:54 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/31 21:46:56 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	check_sorted(t_list *stack_a, size_t n_args)
{
	t_node	*tmp;

	if (!stack_a->head)
		exit(ft_putstr_fd("Error\n", 2));
	if (l_len(stack_a) != n_args)
		return (0);
	tmp = stack_a->head;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

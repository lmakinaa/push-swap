/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tolati.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:39:49 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/09 10:55:00 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	sort_tolati(t_list **stack_a)
{
	t_node	*head;

	head = (*stack_a)->head;
	if (head->value > head->next->value)
	{
		sx(*stack_a, "sa");
		head = (*stack_a)->head;
		if (head->value > head->next->next->value)
			rrx(*stack_a, "rra");
		else if (head->next->value > head->next->next->value)
			return (sx(*stack_a, "sa"), rx(*stack_a, "ra"));
	}
	else if (head->next->value > head->next->next->value)
	{
		if (head->value < head->next->next->value)
			return (sx(*stack_a, "sa"), rx(*stack_a, "ra"));
		else
			rrx(*stack_a, "rra");
	}
}

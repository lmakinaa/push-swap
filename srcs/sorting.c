/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:11:53 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/03 18:28:32 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	sorting(t_list **stack_a, t_list **stack_b, int argc)
{
	(void) stack_b;
	if (argc == 2)
		return (sx(*stack_a, "sa"));
	else if (argc == 3)
		return (sort_tolati(stack_a));
	else if (argc > 3)
		maymknch_sort(stack_a, stack_b, argc);
}

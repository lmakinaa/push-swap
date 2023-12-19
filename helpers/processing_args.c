/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:13:08 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 17:35:34 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	processing_args(char **instructons, t_list *stack_a, t_list *stack_b)
{
	int		i;

	i = 0;
	while (instructons[i])
	{
		if (ft_strcmp(instructons[i], "sa") == 0)
			sx(stack_a);
		else if (ft_strcmp(instructons[i], "sb") == 0)
			sx(stack_b);
		else if (ft_strcmp(instructons[i], "ss") == 0)
			ss(stack_a, stack_b);
		else if (ft_strcmp(instructons[i], "pa") == 0)
			px(stack_a, stack_b);
		else if (ft_strcmp(instructons[i], "pb") == 0)
			px(stack_b, stack_a);
		else if (ft_strcmp(instructons[i], "ra") == 0)
			rx(stack_a);
		else if (ft_strcmp(instructons[i], "rb") == 0)
			rx(stack_b);
		else if (ft_strcmp(instructons[i], "rr") == 0)
			rr(stack_a, stack_b);
		else if (ft_strcmp(instructons[i], "rra") == 0)
			rrx(stack_a);
		else if (ft_strcmp(instructons[i], "rrb") == 0)
			rrx(stack_b);
		else if (ft_strcmp(instructons[i], "rrr") == 0)
			rrr(stack_a, stack_b);
		else
			fail_exit();
		i++;
	}
}

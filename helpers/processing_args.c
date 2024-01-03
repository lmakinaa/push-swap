/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:13:08 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/02 16:03:35 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	process_instruction(char *instruction, t_list *stack_a, t_list *stack_b)
{
	if (ft_strcmp(instruction, "sa") == 0)
		sx(stack_a, NULL);
	else if (ft_strcmp(instruction, "sb") == 0)
		sx(stack_b, NULL);
	else if (ft_strcmp(instruction, "ss") == 0)
		ss(stack_a, stack_b, NULL);
	else if (ft_strcmp(instruction, "pa") == 0)
		px(stack_a, stack_b, NULL);
	else if (ft_strcmp(instruction, "pb") == 0)
		px(stack_b, stack_a, NULL);
	else if (ft_strcmp(instruction, "ra") == 0)
		rx(stack_a, NULL);
	else if (ft_strcmp(instruction, "rb") == 0)
		rx(stack_b, NULL);
	else if (ft_strcmp(instruction, "rr") == 0)
		rr(stack_a, stack_b, NULL);
	else if (ft_strcmp(instruction, "rra") == 0)
		rrx(stack_a, NULL);
	else if (ft_strcmp(instruction, "rrb") == 0)
		rrx(stack_b, NULL);
	else if (ft_strcmp(instruction, "rrr") == 0)
		rrr(stack_a, stack_b, NULL);
	else
		fail_exit();
}

void	processing_args(char **instructions, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		process_instruction(instructions[i], stack_a, stack_b);
		i++;
	}
}

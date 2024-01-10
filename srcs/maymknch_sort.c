/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maymknch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:35:24 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/09 11:38:15 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	list_init_pos(t_list **stack_a)
{
	t_node	*head;
	int		i;

	i = 0;
	head = (*stack_a)->head;
	while (head)
	{
		head->pos = i;
		i++;
		head = head->next;
	}
}

void	push_until_three(t_list **stack_a, t_list **stack_b, int argc)
{
	int		i;
	int		pushed;

	i = 0;
	pushed = 0;
	while (argc > 6 && i < argc && pushed < argc / 2)
	{
		if ((*stack_a)->head->index <= argc / 2)
		{
			px(*stack_b, *stack_a, "pb");
			pushed++;
		}
		else
			rx(*stack_a, "ra");
		i++;
	}
	while (argc - pushed > 3)
	{
		px(*stack_b, *stack_a, "pb");
		pushed++;
	}
}

void	targeting(t_list **stack_a, t_list **stack_b)
{
	t_node	*head_b;
	int		pos_target;

	head_b = (*stack_b)->head;
	pos_target = 0;
	while (head_b)
	{
		pos_target = get_pos_target(stack_a, head_b->index,
				INT_MAX, pos_target);
		head_b->pos_target = pos_target;
		head_b = head_b->next;
	}
}

void	maymknch_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*copy;
	t_node	*head_b;

	copy = l_copy(*stack_a);
	list_indexing(stack_a, &copy);
	push_until_three(stack_a, stack_b, argc);
	head_b = (*stack_b)->head;
	sort_tolati(stack_a);
	while ((*stack_b)->head)
	{
		list_init_pos(stack_a);
		list_init_pos(stack_b);
		targeting(stack_a, stack_b);
		move_cost_init(stack_a, stack_b);
		lowest_cost_move(stack_a, stack_b);
	}
	if (check_sorted(*stack_a, argc) != 1)
		fix_stack(stack_a, argc);
}

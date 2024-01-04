/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maymknch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:35:24 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/04 20:14:57 by ijaija           ###   ########.fr       */
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

	i = 0;
	while (i < argc - 3)
	{
		px(*stack_b, *stack_a, "pb");
		i++;
	}
}

void	maymknch_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*copy;
	t_node	*head_b;
	t_node	*head_b1;
	int		pos_target;

	copy = l_copy(*stack_a);
	list_indexing(stack_a, &copy);
	push_until_three(stack_a, stack_b, argc);
	head_b = (*stack_b)->head;
	head_b1 = (*stack_b)->head;
	sort_tolati(stack_a);
	while (head_b)
	{
		list_init_pos(stack_a);
		list_init_pos(stack_b);
		pos_target = 0;
		while (head_b1)
		{
			pos_target = get_pos_target(stack_a, head_b1->index, INT_MAX, pos_target);
			head_b1->pos_target = pos_target;
			head_b1 = head_b1->next;
		}
		move_cost_init(stack_a, stack_b);
		lowest_cost_move(stack_a, stack_b);
		// here is an imfinite loop rb rb rb rb rb that needs fixing
	}
	l_display(*stack_a);
	// if (check_sorted(*stack_a, argc) != 1)
	// 	fix_stack(stack_a);
}

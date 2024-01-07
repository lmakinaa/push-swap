/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maymknch_sort_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:45:30 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:32:45 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

/* get_pos_target:
*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element can
*	be placed somewhere in between elements in stack A, by checking whether
*	there is an element in stack A with a bigger index. If not, it finds the
*	element with the smallest index in A and assigns that as the target position.
*/

int	get_pos_target(t_list **s_a, int index_b, int target_i, int target_pos)
{
	t_node *head_a;

	head_a = (*s_a)->head;
	while (head_a)
	{
		if (head_a->index > index_b && head_a->index < target_i)
		{
			target_i = head_a->index;
			target_pos = head_a->pos;
		}
		head_a = head_a->next;
	}
	if (target_i != INT_MAX)
		return (target_pos);
	head_a = (*s_a)->head;
	while (head_a)
	{
		if (head_a->index < target_i)
		{
			target_i = head_a->index;
			target_pos = head_a->pos;
		}
		head_a = head_a->next;
	}
	return (target_pos);
}

void	move_cost_init(t_list **stack_a, t_list **stack_b)
{
	t_node	*head_b;
	t_node	*head_a;
	int		stack_a_len;
	int		stack_b_len;

	stack_a_len = l_len(*stack_a);
	stack_b_len = l_len(*stack_b);
	head_b = (*stack_b)->head;
	head_a = (*stack_a)->head;
	while (head_b)
	{
		head_b->move_cost_a = head_b->pos_target;
		if (head_b->pos_target > stack_a_len / 2)
			head_b->move_cost_a = (stack_a_len - head_b->pos_target) * -1;
		head_b->move_cost_b = head_b->pos;
		if (head_b->pos > stack_b_len / 2)
			head_b->move_cost_b = (stack_b_len - head_b->pos) * -1;
		head_b = head_b->next;
	}
}

void	move_stacks(t_list **s_a, t_list **s_b, int mov_a, int mov_b)
{
	int	moves_a;
	int	moves_b;

	moves_a = mov_a;
	moves_b = mov_b;
	if (moves_a < 0 && moves_b < 0)
		rev_rot_both(s_a, s_b, &moves_a, &moves_b);
	else if (moves_a > 0 && moves_b > 0)
		rot_both(s_a, s_b, &moves_a, &moves_b);
	rot_stack(s_a, &moves_a, "ra", "rra");
	rot_stack(s_b, &moves_b, "rb", "rrb");
	px(*s_a, *s_b, "pa");
}

void	lowest_cost_move(t_list **stack_a, t_list **stack_b)
{
	int		lowest_cost;
	int		move_cost_a;
	int		move_cost_b;
	t_node	*head_b;
	
	head_b = (*stack_b)->head;
	lowest_cost = INT_MAX;
	while (head_b && (*stack_a)->head)
	{
		if (ft_abs(head_b->move_cost_a) + ft_abs(head_b->move_cost_b) < ft_abs(lowest_cost))
		{
			lowest_cost = ft_abs(head_b->move_cost_a) + ft_abs(head_b->move_cost_b);
			move_cost_a = head_b->move_cost_a;
			move_cost_b = head_b->move_cost_b;
		}
		head_b = head_b->next;
	}
	move_stacks(stack_a, stack_b, move_cost_a, move_cost_b);
}

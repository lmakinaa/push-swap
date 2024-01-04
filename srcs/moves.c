/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:17 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/04 19:55:18 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	rev_rot_both(t_list **s_a, t_list **s_b, int *moves_a, int *moves_b)
{
	while (*moves_a < 0 && *moves_b < 0)
	{
		rrr(*s_a, *s_b, "rrr");
		(*moves_a)++;
		(*moves_b)++;
	}
}

void	rot_both(t_list **s_a, t_list **s_b, int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		rr(*s_a, *s_b, "rr");
		(*moves_a)--;
		(*moves_b)--;
	}
}

void	rot_stack(t_list **stack, int *moves, char *s_rx, char *s_rrx)
{
	while (*moves)
	{
		if (*moves > 0)
		{
			rx(*stack, s_rx);
			(*moves)--;
		}
		else if (*moves < 0)
		{
			rrx(*stack, s_rrx);
			(*moves)++;
		}
	}
}

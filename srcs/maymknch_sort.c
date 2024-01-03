/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maymknch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:35:24 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/03 19:23:39 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	maymknch_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*copy;

	copy = l_copy(*stack_a);
	list_indexing(stack_a, &copy);
	l_display(*stack_a);
	(void) stack_b;
	(void) argc;
}

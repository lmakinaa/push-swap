/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:30:54 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/07 15:56:23 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	main(int argc, char **argv)
{
	int		*args;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	args = NULL;
	if (args_parsing(&argc, &argv, &args) == -1)
		fail_exit();
	stack_a = array_to_list(args, argc);
	stack_b = c_list();
	if (check_sorted(stack_a, argc) == 1)
		return (freeingx(argv), free(args), l_free(&stack_a), 0);
	sorting(&stack_a, &stack_b, argc);
	freeingx(argv);
	free(args);
	l_free(&stack_a);
	l_free(&stack_b);
	return (0);
}

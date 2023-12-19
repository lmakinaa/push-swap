/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:39 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/19 16:52:14 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// printf("%s", file);
	// for (int i = 0; i < argc - 1; i++)
	// 	ft_printf("%d\n", args[i]);
	
#include "./../includes/helpers.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	**instructions;
	t_list	*stack_a;
	t_list	*stack_b;
	int		args[argc - 1];

	if (argc == 1)
		return (0);
	if (args_parsing(argc, argv, args) == -1)
		fail_exit();
	file = reading_input();
	if (instructions_check(file) == -1)
		fail_exit();
	instructions = ft_split(file, '\n');
	free(file);
	stack_a = array_to_list(args, argc - 1);
	stack_b = c_list();
	processing_args(instructions, stack_a, stack_b);
	check_ok_or_ko(stack_a, argc - 1);
	return (0);
}

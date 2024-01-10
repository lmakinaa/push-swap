/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:08:39 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/10 10:00:40 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	**instructions;
	t_list	*s_a;
	t_list	*s_b;
	int		*args;

	if (argc == 1)
		return (0);
	args = NULL;
	if (args_parsing(&argc, &argv, &args) == -1)
		fail_exit();
	s_a = array_to_list(args, argc);
	file = reading_input();
	if (check_sorted(s_a, argc) == 1 && ft_split(file, '\n') == NULL)
		return (freeingx(argv), free(args), l_free(&s_a), ft_printf("OK\n"));
	if (instructions_check(file) == -1)
		fail_exit();
	instructions = ft_split(file, '\n');
	free(file);
	freeingx(argv);
	free(args);
	s_b = c_list();
	processing_args(instructions, s_a, s_b);
	return (check_ok_or_ko(s_a, argc), 0);
}

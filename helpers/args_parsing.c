/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:16:04 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 11:16:21 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

int	args_parsing(int argc, char **argv, int *args)
{
	int		i;
	int		nbr;
	int		j;

	i = argc;
	while (i-- > 1)
	{
		if (custom_atoi(argv[i]) == 9999999999999)
			return (-1);
		args[i - 1] = custom_atoi(argv[i]);
	}
	i = 0;
	while (i < argc - 1)
	{
		nbr = args[i];
		j = 0;
		while (j < argc - 1)
		{
			if (i != j && nbr == args[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

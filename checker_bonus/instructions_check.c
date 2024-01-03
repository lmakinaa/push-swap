/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:49:12 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/31 19:42:52 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static int	check_duos(char *file, int i)
{
	if (file[i] == 's' && file[i + 1] == 'a')
		i += 2;
	else if (file[i] == 's' && file[i + 1] == 'b')
		i += 2;
	else if (file[i] == 's' && file[i + 1] == 's')
		i += 2;
	else if (file[i] == 'p' && file[i + 1] == 'a')
		i += 2;
	else if (file[i] == 'p' && file[i + 1] == 'b')
		i += 2;
	else if (file[i] == 'r' && file[i + 1] == 'a')
		i += 2;
	else if (file[i] == 'r' && file[i + 1] == 'b')
		i += 2;
	else
		return (-1);
	return (i);
}

static int	check_trios(char *file, int i)
{
	if (file[i] == 'r' && file[i + 1] == 'r' && file[i + 2] == 'r')
		i += 3;
	else if (file[i] == 'r' && file[i + 1] == 'r' && file[i + 2] == 'a')
		i += 3;
	else if (file[i] == 'r' && file[i + 1] == 'r' && file[i + 2] == 'b')
		i += 3;
	else if (file[i] == 'r' && file[i + 1] == 'r')
		i += 2;
	else
		return (-1);
	return (i);
}

int	instructions_check(char *file)
{
	int	i;

	i = 0;
	if (!file)
		exit(ft_printf("KO\n"));
	while (file[i])
	{
		if (file[i] == '\n')
			i++;
		else if (check_duos(file, i) != -1)
			i = check_duos(file, i);
		else if (check_trios(file, i) != -1)
			i = check_trios(file, i);
		else
			return (-1);
	}
	return (0);
}

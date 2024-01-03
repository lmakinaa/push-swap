/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:16:04 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/31 18:35:34 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	printing(int *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ft_printf("%d\n", argv[i]);
		i++;
	}
}

char	**spliting(int argc, char **argv)
{
	char	**res;
	char	**tmp;
	int		i;

	res = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		if (!tmp)
			return (NULL);
		if (!res)
		{
			res = malloc(sizeof(char *));
			if (!res)
				return (NULL);
			res[0] = NULL;
		}
		res = str_arrays_join(res, tmp);
		i++;
	}
	return (res);
}

static int	count_strings(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	freeingx(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	args_parsing(int *argc, char ***argv, int **args)
{
	int		i;
	int		nbr;
	int		j;

	*argv = spliting(*argc, *argv);
	*argc = count_strings(*argv);
	*args = malloc((*argc) * sizeof(int));
	i = *argc;
	while (i-- > 0)
	{
		if (custom_atoi((*argv)[i]) == 9999999999999)
			return (freeingx(*argv), free(*args), -1);
		(*args)[i] = custom_atoi((*argv)[i]);
	}
	i = -1;
	while (++i < *argc)
	{
		nbr = (*args)[i];
		j = -1;
		while (++j < *argc)
			if (i != j && nbr == (*args)[j])
				return (freeingx(*argv), free(*args), -1);
	}
	return (0);
}

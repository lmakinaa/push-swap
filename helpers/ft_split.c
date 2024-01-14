/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:39:29 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/14 17:56:18 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	cleaner(char **res)
{
	char	**start;

	start = res;
	while (*res)
	{
		free(*res);
		res++;
	}
	free(start);
}

static int	ft_countword(char const *str, char sep)
{
	size_t	i;
	int		count;
	size_t	size;

	i = 0;
	count = 0;
	size = ft_strlen(str);
	if (*str == '\0')
		return (0);
	while (i < size)
	{
		if (str[i] != sep)
		{
			count++;
			while (str[i] != sep && i < size)
				i++;
		}
		i++;
	}
	if (count == 0)
		fail_exit();
	return (count);
}

static char	*custom_strdup(char	const *s, char sep)
{
	int		i;
	int		j;
	char	*res;
	char	*resaddr;

	i = 0;
	j = 0;
	while (s[i] && s[i] != sep)
		i++;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	resaddr = res;
	while (j < i && s[j] != sep)
	{
		*res = s[j];
		res++;
		j++;
	}
	*res = '\0';
	return (resaddr);
}

static	int	spliting_process(char **res, char const *s, char c, int size)
{
	int	i;

	i = 0;
	while (i < size && *s)
	{
		if (*s != c)
		{
			res[i] = custom_strdup(s, c);
			if (!res[i])
			{
				cleaner(res);
				return (0);
			}
			while (*s != c && *s)
				s++;
			i++;
		}
		while (*s && *s == c)
			s++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**res;

	if (!s)
		return (NULL);
	if (*s == '\0')
		fail_exit();
	size = ft_countword(s, c);
	res = malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!(spliting_process(res, s, c, size)))
		return (NULL);
	return (res);
}

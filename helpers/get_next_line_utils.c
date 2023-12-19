/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:10:39 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/19 16:48:25 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	*freeing(char *str)
{
	free(str);
	return (0);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (0);
}

char	*custom_strjoin(char *s1, char *s2)
{
	int		i;
	char	*res;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (freeing(s1));
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2)
		res[i++] = *(s2++);
	res[i] = '\0';
	free(s1);
	return (res);
}

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*line_fill(char *stock)
{
	int		i;
	char	*res;

	i = 0;
	if (!stock[0])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		res = malloc((i + 2) * sizeof(char));
	else
		res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		res[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arrays_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:45:12 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/30 13:36:34 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

char	**str_arrays_join(char **dest, char **tmp)
{
	int		i;
	int		total;
	int		j;
	char	**res;

	i = 0;
	total = 0;
	while (dest[total])
		total++;
	while (tmp[i])
		i++;
	total += i;
	res = malloc((total + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (dest[++i])
		res[i] = dest[i];
	j = 0;
	while (tmp[j])
		res[i++] = tmp[j++];
	res[i] = NULL;
	return (free(tmp), free(dest), res);
}

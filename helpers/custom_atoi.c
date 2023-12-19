/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:17:47 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 10:57:32 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

static long	part2(int i, int sign, const char *str)
{
	int		newi;
	long	res;
	long	max;

	newi = i;
	max = INT_MAX;
	res = 0;
	while (str[newi] && ft_isdigit(str[newi]))
	{
		res = res * 10 + (str[newi] - '0');
		if ((res > max && sign == 1) || (res > max + 1 && sign == -1))
			return (9999999999999);
		newi++;
	}
	if (str[newi] && !ft_isdigit(str[newi]))
		return (9999999999999);
	return (res * sign);
}

long	custom_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (part2(i, sign, str));
}

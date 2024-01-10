/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:31:36 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/10 11:33:22 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	some_cleaning(t_list **s_b, char **instructions)
{
	cleaner(instructions);
	l_free(s_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:18:54 by ijaija            #+#    #+#             */
/*   Updated: 2024/01/10 11:35:24 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

char	*reading_input(void)
{
	char	*file;
	char	*line;
	int		fd;

	fd = 0;
	file = NULL;
	line = get_next_line(fd);
	while (line)
	{
		file = custom_strjoin(file, line);
		free(line);
		line = get_next_line(fd);
	}
	return (file);
}

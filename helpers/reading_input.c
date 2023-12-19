/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:18:54 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 11:49:19 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

// int main()
// {
// 	int fd;
// 	char	*file = NULL;
// 	char *line;


// 	fd = 0;
// 	while ((line = get_next_line(fd)))
// 		file = custom_strjoin(file, line);
// 	printf("%s", file);
// 	return (0);
// }

char	*reading_input(void)
{
	char	*file;
	char	*line;
	int		fd;

	fd = 0;
	file = NULL;
	while ((line = get_next_line(fd)))
		file = custom_strjoin(file, line);
	return (file);
}

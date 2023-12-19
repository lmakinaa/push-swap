/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaija <ijaija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:30:10 by ijaija            #+#    #+#             */
/*   Updated: 2023/12/18 11:32:39 by ijaija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/helpers.h"

void	*reading(int fd, char *stock)
{
	char	*buffer;
	int		readed;

	readed = 1;
	while (!ft_strchr(stock, '\n') && readed != 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (freeing(stock));
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buffer);
			if (stock)
				free(stock);
			return (NULL);
		}
		buffer[readed] = '\0';
		stock = custom_strjoin(stock, buffer);
		free(buffer);
	}
	return (stock);
}

char	*cleaning(char *stock)
{
	int		i;
	int		j;
	char	*new_stock;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
		return (freeing(stock));
	new_stock = malloc((ft_strlen(stock) - i + 1) * sizeof(char));
	if (!new_stock)
		return (freeing(stock));
	i++;
	j = 0;
	while (stock[i])
		new_stock[j++] = stock[i++];
	new_stock[j] = '\0';
	free(stock);
	return (new_stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!stock || (stock && !ft_strchr(stock, '\n')))
		stock = reading(fd, stock);
	if (!stock)
		return (NULL);
	line = line_fill(stock);
	if (!line)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	stock = cleaning(stock);
	return (line);
}

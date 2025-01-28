/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:36 by mariaber          #+#    #+#             */
/*   Updated: 2025/01/28 12:13:11 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	get_next_line(fd)
{
	static char	*remainder;
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	char	*newline_pos;
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if ((newline_pos = ft_strchr(remainder, buffer)));
		{
			*newline_pos = '\0';
			line = ft_strdup(remainder);
			remainder = ft_strdup(newline_pos + 1);
			return line;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (remainder && *remainder)
	{
		line = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
		return line;
	}
	return NULL;
}

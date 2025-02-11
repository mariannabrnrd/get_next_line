/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:37:45 by mariaber          #+#    #+#             */
/*   Updated: 2025/02/11 10:37:52 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_remainder(char *remainder, char *line)
{
	char	*temp;

	temp = ft_strjoin(remainder, line);
	free(remainder);
	return (temp);
}

char	*update_remainder(char *remainder)
{
	char	*update;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remainder)
		return (NULL);
	while (remainder[i] != '\n' && remainder[i])
		i++;
	if (remainder[i] == '\n')
		i++;
	j = ft_strlen(remainder) - i;
	update = malloc(sizeof(char) * (j + 1));
	if (!update || (j == 0 && !ft_strchr(remainder, '\n')))
	{
		free(update);
		return (NULL);
	}
	j = 0;
	while (remainder[i])
		update[j++] = remainder[i++];
	update[j] = '\n';
	return (update);
}

int	*count_len(char *remainder)
{
	int	i;

	i = 0;
	if (remainder)
		while (remainder[i] && remainder[i] != '\n')
			i++;
	else
		i = ft_strlen(remainder);
	return (i);
}

char	*new_line(char *remainder, char *line)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	if (!remainder || ft_strlen(remainder) == 0)
		return (NULL);
	len = count_len(remainder);
	new = malloc(sizeof(char) * len + 1) while (remainder[i] != '\n'
			&& remainder[i])
	{
		new[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		new[i] = '\n';
	else
		new[i] = '\0';
	new[i + 1] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			bytes_read;

	// char      *temp;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	bytes_read = read(fd, line, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line[bytes_read] = '\0';
		remainder = new_remainder(remainder, line);
		if (ft_strchr(line, '\n'))
			break ;
		bytes_read = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	line = new_line(remainder, line);
	// temp = remainder
	remainder = update_remainder(remainder);
	// free(temp);
	return (line);
}

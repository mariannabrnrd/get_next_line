/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:48:29 by mariaber          #+#    #+#             */
/*   Updated: 2025/02/12 11:48:32 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*update_remainder(char *remainder);
char	*new_remainder(char *remainder, char *line);
char	*new_line(char *remainder);
int		count_len(char *remainder);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, char c);

#endif

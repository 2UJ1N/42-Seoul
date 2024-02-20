/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:48:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/20 14:53:52 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(const char *s);
int		ft_strchr(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *tmp, char const *buffer);
char	*ft_substr(char const *s, int start, int end);

void	free_memory(char **backup, char **line);
int		print_line(char **backup, char **line);
int		update_buffer(int fd, ssize_t *idx, char **backup);
char	*get_next_line(int fd);

#endif
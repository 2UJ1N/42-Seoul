/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:48:32 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/20 16:01:44 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
int		ft_strchr(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *tmp, const char *buffer);
char	*ft_substr(const char *s, int start, int end);

void	free_memory(char **backup, char **line);
int		print_line(char **backup, char **line);
int		update_buffer(int fd, ssize_t *idx, char **backup);
char	*get_next_line(int fd);

#endif
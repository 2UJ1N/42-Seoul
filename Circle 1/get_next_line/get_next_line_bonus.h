/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:43:50 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/21 17:29:43 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(const char *s);
int		ft_strchr(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *tmp, const char *buffer);
char	*ft_substr(const char *s, int start, int end);

void	free_memory(char **backup, char **line);
int		print_line(char **backup, char **line);
void	backup_free(char **backup);
int		update_buffer(int fd, ssize_t *idx, char **backup, char *buffer);
char	*get_next_line(int fd);

#endif
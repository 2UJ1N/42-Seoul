/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:47:51 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/20 15:07:38 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_memory(char **backup, char **line)
{
	free(*backup);
	*backup = NULL;
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

int	print_line(char **backup, char **line)
{
	int		i;
	char	*tmp;

	i = ft_strchr(*backup);
	if (i == -1)
		i = ft_strlen(*backup);
	*line = ft_substr(*backup, 0, i + 1);
	if (!*line)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	tmp = *backup;
	*backup = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
	free(tmp);
	if (!*backup)
	{
		free(*line);
		return (1);
	}
	return (0);
}

int	update_buffer(int fd, ssize_t *idx, char **backup)
{
	char	*tmp;
	char	*buffer[BUFFER_SIZE + 1];

	while (ft_strchr(*backup) == -1)
	{
		*idx = read(fd, buffer, BUFFER_SIZE);
		if (*idx == -1)
		{
			free(*backup);
			*backup = NULL;
			return (1);
		}
		else if (!*idx)
			break ;
		buffer[*idx] = 0;
		tmp = *backup;
		*backup = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!*backup)
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		*idx;
	char		*line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	if (update_buffer(fd, &idx, &backup))
		return (NULL);
	if (print_line(&backup, &line))
		return (NULL);
	if (*backup == '\0' && idx == 0)
		free_memory(&backup, &line);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:43:58 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/21 17:27:49 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_memory(char **buffer, char **backup)
{
	free(*backup);
	*backup = NULL;
	if (**buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
}

int	update_buffer(int fd, ssize_t *idx, char **backup, char *buffer)
{
	char	*tmp;

	while (ft_strchr(*backup) == -1)
	{
		*idx = read(fd, buffer, BUFFER_SIZE);
		if (*idx == -1)
		{
			free(buffer);
			buffer = NULL;
			free(*backup);
			*backup = NULL;
			return (1);
		}
		else if (*idx == 0)
			break ;
		buffer[*idx] = 0;
		tmp = *backup;
		*backup = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!*backup)
			return (free(buffer), buffer = NULL, 1);
	}
	return (0);
}

int	print_line(char **line, char **backup)
{
	int		i;
	char	*tmp;

	i = ft_strchr(*backup);
	if (i == -1)
		i = ft_strlen(*backup);
	*line = ft_substr(*backup, 0, i + 1);
	if (!(*line))
		return (free(*backup), *backup = NULL, 1);
	tmp = *backup;
	*backup = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
	free(tmp);
	if (!(*backup))
	{
		return (free(*line), line = NULL, 1);
	}
	return (0);
}

void	backup_free(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
	}
}

char	*get_next_line(int fd)
{
	ssize_t		idx;
	char		*line;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (backup_free(&backup), free(buffer), buffer = NULL, NULL);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (free(buffer), buffer = NULL, NULL);
	}
	if (update_buffer(fd, &idx, &backup, buffer))
		return (NULL);
	line = NULL;
	if (print_line(&line, &backup))
		return (free(buffer), buffer = NULL, NULL);
	if (*backup == '\0' && idx == 0)
		free_memory(&line, &backup);
	return (free(buffer), buffer = NULL, line);
}

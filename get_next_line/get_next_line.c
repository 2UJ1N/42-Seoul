/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:43:58 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/20 20:03:35 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_memory(char **backup, char **buffer)
{
	free(*backup);
	*backup = NULL;
	if (**buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
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
	if (!(*line))
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	tmp = *backup;
	*backup = ft_substr(tmp, i + 1, ft_strlen(tmp) - i - 1);
	free(tmp);
	if (!(*backup))
	{
		free(*line);
		return (1);
	}
	return (0);
}

int	update_buffer(int fd, ssize_t *idx, char **backup)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	while (ft_strchr(*backup) == -1)
	{
		*idx = read(fd, &buffer, BUFFER_SIZE);
		if (*idx == -1)
		{
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
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		idx;
	char		*buffer;
	static char	*backup;

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
	if (print_line(&backup, &buffer))
		return (NULL);
	if (*backup == '\0' && idx == 0)
		free_memory(&backup, &buffer);
	return (buffer);
}
#include <fcntl.h>
#include <stdio.h>
int main(void){
	int n = open("text2.txt", O_RDONLY);
	printf("%s", get_next_line(n));

}
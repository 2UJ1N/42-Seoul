/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:46:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/04/02 15:35:47 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

int	ft_strchr(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (s[cnt] == '\n')
			return (cnt);
		cnt++;
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*result;

	i = -1;
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (s[++i])
		result[i] = s[i];
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(const char *tmp, const char *buffer)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(tmp) + ft_strlen(buffer);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (*tmp)
		result[i++] = *tmp++;
	while (*buffer)
		result[i++] = *buffer++;
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, int start, int end)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	if (!s)
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
		return (result);
	}
	if (len <= end || len - start < end)
		end = len - start;
	result = (char *)malloc(sizeof(char) * (end + 1));
	if (!result)
		return (free(result), result = NULL, NULL);
	while (start + i < len && i < end)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

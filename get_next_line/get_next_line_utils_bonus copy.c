/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:48:13 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/20 15:20:21 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*result;

	i = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		result[i] = s1[i];
	}
	result[i] = '\0';
	return (result);
}

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

char	*ft_substr(char const *s, int start, int end)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
	{
		result = ft_strdup("");
		if (!result)
			return (NULL);
		return (result);
	}
	if (len <= end || len - start < end)
		end = len - start;
	result = (char *)malloc(sizeof(char) * (end + 1));
	if (result == NULL)
		return (NULL);
	while (start + i < len && i < end)
	{
		result[i] = s[start + 1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

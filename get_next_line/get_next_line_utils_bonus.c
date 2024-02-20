#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	size_t	i;
	char	*result;

	s1_len = ft_strlen(s1);
	result = ft_calloc(sizeof(char), s1_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = s1[i];
	return (result);
}

int	ft_strchr(const char *s)
{
	int i;

    i = 0;
	while (s[i] != '\0')
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
	return (-1);
}

char	*ft_strjoin(char const *tmp, char const *buffer)
{
	int     i;
    int     len;
	char	*result;

    i = 0;
    len = ft_strlen(tmp) + ft_strlen(buffer);
    result = (char *)malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    while (*tmp != NULL)
        result[i++] = *tmp++;
    while(*buffer != NULL)
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
    int     i;
    int     len;
	char	*result;

    i = 0;
    len = ft_strlen(s);
	if (s == NULL)
    {
        result = ft_strdup("");
        if (result == NULL)
            return (NULL);
        return (result);
    }
	if (len <= end || len - start < end )
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

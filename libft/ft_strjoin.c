/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:27:22 by youjlee           #+#    #+#             */
/*   Updated: 2023/12/19 14:27:25 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	result_len;
	char	*result;

	if ((s1 == NULL && s2 == NULL))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result_len = s1_len + s2_len;
	result = (char *)ft_calloc(result_len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_strlcat(result, s2, result_len + 1);
	return (result);
}

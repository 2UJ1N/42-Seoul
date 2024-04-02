/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:26 by youjlee           #+#    #+#             */
/*   Updated: 2023/12/19 14:25:29 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	char	char_c;

	result = (char *)s;
	char_c = (char)c;
	while (*result != '\0' && *result != char_c)
		result++;
	if (*result == char_c)
		return (result);
	return (NULL);
}

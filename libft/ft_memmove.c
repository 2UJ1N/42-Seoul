/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:22:31 by youjlee           #+#    #+#             */
/*   Updated: 2023/12/19 14:22:34 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_char;
	char	*src_char;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	dst_char = (char *)dst;
	src_char = (char *)src;
	while (i < len)
	{
		if (dst <= src)
			dst_char[i] = src_char[i];
		else
			dst_char[len - 1 - i] = src_char[len - 1 - i];
		i++;
	}
	return (dst);
}

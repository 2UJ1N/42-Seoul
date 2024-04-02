/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:16:36 by youjlee           #+#    #+#             */
/*   Updated: 2023/12/19 14:16:40 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (!(count <= -1 / size))
		return (NULL);
	result = (void *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	ft_memset(result, 0, size * count);
	return (result);
}

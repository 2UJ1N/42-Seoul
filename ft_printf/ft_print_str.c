/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:56:44 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 16:21:44 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_print_c(int c, int *cnt)
{
	if (write(1, &c, 1) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

int	ft_print_s(char *s, int *cnt)
{
	size_t	len;

	len = ft_strlen(s);
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*cnt = -1;
			return (-1);
		}
		*cnt += 6;
		return ;
	}
	if (write(1, s, len) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += len;
}

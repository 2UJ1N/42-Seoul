/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:56:44 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 19:44:44 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_print_c(int c, int *cnt)
{
	if (write(1, &c, 1) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

void	ft_print_s(char *str, int *cnt)
{
	size_t	len;

	len = ft_strlen(str);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*cnt = -1;
			return ;
		}
		*cnt += 6;
		return ;
	}
	if (write(1, str, len) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += len;
}

void	ft_print_p(void *p, int *cnt)
{
	unsigned long long	addr;

	addr = (unsigned long long)p;
	if (write(1, "0x", 2) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 2;
	if (addr == 0)
	{
		if (write(1, "0", 1) == -1)
		{
			*cnt = -1;
			return ;
		}
		*cnt += 1;
	}
	else
		ft_print_hex(addr, cnt);
}

void	ft_print_hex(unsigned int n, int *cnt)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0)
		return ;
	*cnt += 1;
	ft_print_hex(n / 16, cnt);
	if (*cnt == -1)
		return ;
	if (write(1, hex + (n % 16), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

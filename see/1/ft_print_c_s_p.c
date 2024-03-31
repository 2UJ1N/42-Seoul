/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:36:01 by woorikim          #+#    #+#             */
/*   Updated: 2023/04/18 17:03:38 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
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

void	ft_print_s(char *s, int *cnt)
{
	size_t	len;

	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
		{
			*cnt = -1;
			return ;
		}
		*cnt += 6;
		return ;
	}
	len = ft_strlen(s);
	if (write(1, s, len) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += len;
}

void	ft_print_hex(unsigned long long addr, int *cnt)
{
	char	*s;

	s = "0123456789abcdef";
	if (addr == 0)
		return ;
	*cnt += 1;
	ft_print_hex(addr / 16, cnt);
	if (*cnt == -1)
		return ;
	if (write(1, s + (addr % 16), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
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
	{
		ft_print_hex(addr, cnt);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:04:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 17:54:06 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_print_hex(addr, cnt, 0);
}

void	ft_print_hex(unsigned int n, int *cnt, int is_upper)
{
	char	*hex;

	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
		return ;
	*cnt += 1;
	ft_print_hex(n / 16, cnt, is_upper);
	if (*cnt == -1)
		return ;
	if (write(1, hex + n % 16, 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

void	ft_print_pcnt(int *cnt)
{
	if (write(1, "%", 1) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

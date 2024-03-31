/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:04:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/31 13:33:57 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned long long n, int *cnt)
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

void	ft_print_x(unsigned int n, int *cnt, int is_x, int visit)
{
	char	*hex;

	if (is_x == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0 && visit == 1)
		return ;
	*cnt += 1;
	ft_print_x(n / 16, cnt, is_x, 1);
	if (*cnt == -1)
		return ;
	if (write(1, hex + (n % 16), 1) == -1)
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

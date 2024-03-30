/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:04:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 19:49:23 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x(unsigned int n, int *cnt, int visit)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0 && visit == 1)
		return ;
	*cnt += 1;
	ft_print_x(n / 16, cnt, 1);
	if (*cnt == -1)
		return ;
	if (write(1, hex + (n % 16), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

void	ft_print_xx(unsigned int n, int *cnt, int visit)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0 && visit == 1)
		return ;
	*cnt += 1;
	ft_print_xx(n / 16, cnt, 1);
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

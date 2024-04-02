/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:40:54 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/31 14:09:11 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *cnt)
{
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
		{
			*cnt = -1;
			return ;
		}
		*cnt += 1;
	}
	ft_print_nbr(n, cnt, 0);
}

void	ft_print_nbr(int n, int *cnt, int visit)
{
	char	*dec;

	dec = "0123456789";
	if (n == 0 && visit == 1)
		return ;
	*cnt += 1;
	ft_print_nbr(n / 10, cnt, 1);
	if (*cnt == -1)
		return ;
	if (n < 0)
	{
		if (write(1, dec - (n % 10), 1) == -1)
		{
			*cnt = -1;
			return ;
		}
	}
	else
	{
		if (write(1, dec + (n % 10), 1) == -1)
		{
			*cnt = -1;
			return ;
		}
	}
}

void	ft_print_unbr(unsigned int n, int *cnt, int visit)
{
	char	*dec;

	dec = "0123456789";
	if (n == 0 && visit == 1)
		return ;
	*cnt += 1;
	ft_print_unbr(n / 10, cnt, 1);
	if (*cnt == -1)
		return ;
	if (write(1, dec + (n % 10), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

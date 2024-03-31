/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:42:55 by woorikim          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:59 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr2(int n, int *cnt, int first)
{
	char	*dec;

	dec = "0123456789";
	if ((first == 0 && n == 0))
		return ;
	*cnt += 1;
	ft_putnbr2(n / 10, cnt, 0);
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

void	ft_putnbr1(int n, int *cnt)
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
	ft_putnbr2(n, cnt, 1);
}

void	ft_print_u(unsigned int n, int *cnt, int first)
{
	char	*s;

	s = "0123456789";
	if (n == 0 && first == 0)
		return ;
	*cnt += 1;
	ft_print_u(n / 10, cnt, 0);
	if (*cnt == -1)
		return ;
	if (write(1, s + (n % 10), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

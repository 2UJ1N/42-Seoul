/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:24:07 by youjlee           #+#    #+#             */
/*   Updated: 2023/12/19 14:24:09 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_digit(int n);

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	long	num;
	char	result[33];

	digit = get_digit(n);
	ft_memset(result, 0, 33);
	num = n;
	if (n < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	digit--;
	while (0 <= digit)
	{
		result[digit] = "0123456789"[num % 10];
		num /= 10;
		digit--;
	}
	ft_putstr_fd(result, fd);
}

static	int	get_digit(int n)
{
	int	digit;

	digit = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

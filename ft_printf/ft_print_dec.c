/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:40:54 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 17:15:46 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int n, int *cnt)
{
	char	*dec;

	dec = "0123456789";
	if (n < 0 && write(1, "-", 1) == -1)
	{
		*cnt = -1;
		return ;
	}
	if (n < 0)
	{
		*cnt += 1;
		n *= -1;
	}
	if (n / 10 != 0)
		ft_print_nbr(n / 10, cnt);
	if (*cnt == -1)
		return ;
	if (write(1, dec + (n % 10), 1) == -1)
		*cnt = -1;
	else
		*cnt += 1;
}

void	ft_print_unbr(unsigned int n, int *cnt, int call)
{
	char	*dec;

	dec = "0123456789";
	if (n == 0 && call == 1)
		return ;
	ft_print_unbr(n / 10, cnt, 1);
	if (*cnt == -1)
		return ;
	if (write(1, &dec[n % 10], 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

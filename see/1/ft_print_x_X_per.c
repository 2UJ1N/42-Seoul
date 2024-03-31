/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:15:22 by woorikim          #+#    #+#             */
/*   Updated: 2023/04/18 16:08:19 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x(unsigned int n, int *cnt, int first)
{
	char	*s;

	s = "0123456789abcdef";
	if (n == 0 && first == 0)
		return ;
	*cnt += 1;
	ft_print_x(n / 16, cnt, 0);
	if (*cnt == -1)
		return ;
	if (write(1, s + (n % 16), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

void	ft_print_upperx(unsigned int n, int *cnt, int first)
{
	char	*s;

	s = "0123456789ABCDEF";
	if (n == 0 && first == 0)
		return ;
	*cnt += 1;
	ft_print_upperx(n / 16, cnt, 0);
	if (*cnt == -1)
		return ;
	if (write(1, s + (n % 16), 1) == -1)
	{
		*cnt = -1;
		return ;
	}
}

void	ft_print_per(int *cnt)
{
	if (write(1, "%", 1) == -1)
	{
		*cnt = -1;
		return ;
	}
	*cnt += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:05:37 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 17:54:10 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chk_type(const char *str, va_list *ap, int *cnt);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	char	*s;

	cnt = 0;
	s = (char *)str;
	va_start(ap, str);
	while (*s)
	{
		if (*str == '%')
			chk_type(++s, &ap, &cnt);
		else
		{
			if (write(1, s, 1) == -1)
				return (-1);
			cnt++;
		}
		if (cnt == -1)
			break ;
		s++;
	}
	va_end(ap);
	return (cnt);
}

void	chk_type(const char *str, va_list *ap, int *cnt)
{
	if (*str == 'c')
		ft_print_c(va_arg(*ap, int), cnt);
	else if (*str == 's')
		ft_print_s(va_arg(*ap, char *), cnt);
	else if (*str == 'p')
		ft_print_ptr(va_arg(*ap, void *), cnt);
	else if (*str == 'd' || *str == 'i')
		ft_print_nbr(va_arg(*ap, int), cnt);
	else if (*str == 'u')
		ft_print_unbr(va_arg(*ap, unsigned int), cnt, 0);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_printf_hex(va_arg(*ap, unsigned int), cnt, 0);
		else
			ft_printf_hex(va_arg(*ap, unsigned int), cnt, 1);
	}
	else if (*str == '%')
		ft_print_pcnt(cnt);
	else
		*cnt = -1;
}

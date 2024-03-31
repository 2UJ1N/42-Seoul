/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:41:02 by woorikim          #+#    #+#             */
/*   Updated: 2023/04/18 16:56:49 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	def_printtype(char *s, va_list argptr, int *cnt)
{
	if (*s == 'c')
		ft_print_c(va_arg(argptr, int), cnt);
	else if (*s == 's')
		ft_print_s(va_arg(argptr, char *), cnt);
	else if (*s == 'p')
		ft_print_p(va_arg(argptr, void *), cnt);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr1(va_arg(argptr, int), cnt);
	else if (*s == 'u')
		ft_print_u(va_arg(argptr, unsigned int), cnt, 1);
	else if (*s == 'x')
		ft_print_x(va_arg(argptr, unsigned int), cnt, 1);
	else if (*s == 'X')
		ft_print_upperx(va_arg(argptr, unsigned int), cnt, 1);
	else if (*s == '%')
		ft_print_per(cnt);
	else
		*cnt = -1;
}

int	ft_printf(const char *s, ...)
{
	va_list	argptr;
	int		cnt;
	char	*str;

	str = (char *)s;
	va_start(argptr, s);
	cnt = 0;
	while (*str)
	{
		if (*str == '%')
			def_printtype(++str, argptr, &cnt);
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			cnt++;
		}
		if (cnt == -1)
			break ;
		str++;
	}
	va_end(argptr);
	return (cnt);
}

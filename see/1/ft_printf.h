/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:35:44 by woorikim          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:21 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	ft_print_c(int c, int *cnt);
void	ft_print_s(char *s, int *cnt);
void	ft_print_hex(unsigned long long addr, int *cnt);
void	ft_print_p(void *p, int *cnt);
void	def_printtype(char *s, va_list argptr, int *cnt);
int		ft_printf(const char *s, ...);
void	ft_putnbr2(int n, int *cnt, int first);
void	ft_putnbr1(int n, int *cnt);
void	ft_print_u(unsigned int n, int *cnt, int first);
void	ft_print_x(unsigned int n, int *cnt, int first);
void	ft_print_upperx(unsigned int n, int *cnt, int first);
void	ft_print_per(int *cnt);

#endif
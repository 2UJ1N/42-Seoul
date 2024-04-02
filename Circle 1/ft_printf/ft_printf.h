/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:05:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/31 13:52:08 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
void	chk_type(char *str, va_list ap, int *cnt);
void	ft_print_c(int c, int *cnt);
void	ft_print_s(char *str, int *cnt);
void	ft_print_p(void *p, int *cnt);
void	ft_print_hex(unsigned long long n, int *cnt);
void	ft_print_x(unsigned int n, int *cnt, int is_x, int visit);
void	ft_print_pcnt(int *cnt);
void	ft_putnbr(int n, int *cnt);
void	ft_print_nbr(int n, int *cnt, int visit);
void	ft_print_unbr(unsigned int n, int *cnt, int visit);

#endif
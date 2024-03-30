/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:05:02 by youjlee           #+#    #+#             */
/*   Updated: 2024/03/30 18:25:52 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
void	ft_print_c(int c, int *cnt);
void	ft_print_s(char *s, int *cnt);
void	chk_type(const char *str, va_list *ap, int *cnt);
void	ft_print_nbr(int n, int *cnt);
void	ft_print_unbr(unsigned int n, int *cnt, int call);
void	ft_print_p(void *p, int *cnt);
void	ft_print_hex(unsigned int n, int *cnt, int is_upper);
void	ft_print_pcnt(int *cnt);

#endif

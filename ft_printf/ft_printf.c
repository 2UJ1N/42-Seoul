/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <youjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:05:37 by youjlee           #+#    #+#             */
/*   Updated: 2024/02/21 18:40:47 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int chk_type()
{
    if (c == 'c')
        return (ft_printf_char());
    else if (c == 's')
        return (ft_printf_str());
    else if (c == 'd' || c == 'i')
        return (ft_printf_num());
    else if (c == 'u')
        return (ft_printf_unsignednum());
    else if (c == 'x' || c == 'X')
        return (ft_printf_hex());
    else if (c == 'p')
        return (ft_printf_ptr());
    else if (c == '%')
        return (ft_printf_char());
    return (0);
}

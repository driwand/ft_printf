/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:06:26 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/07 19:25:40 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     print_address(const char *str, va_list *arg, t_flags flg)
{
    int     count;
    int     tmp;
    char    *res;
    
    tmp = va_arg(*arg, int);
    res = to_hexa((int)tmp);
    return (print_string(res, arg, flg));
}
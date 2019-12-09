/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:08:27 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/09 20:46:29 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     get_int_len(int n)
{
    int len;
    unsigned int nb;

    len = 0;
    if (n < 0)
    {
        len++;
        nb = -n;
    }
    else
        nb = n;
    while (nb > 9)
    {
        nb /= 10;
        len++;
    }
    if (nb < 9)
        len++;
    return (len);
}

int apply_width_int(int width)
{
    int count;

    count = 0;
    while (count < width)
    {
        ft_putchar_fd(' ', 1);
        count++;
    }
    return (count);
}

int apply_zero_int(int width)
{
    int count;

    count = 0;
    while (count < width)
    {
        ft_putchar_fd('0', 1);
        count++;
    }
    return (count);
}

int print_integer(va_list *arg, t_flags flg)
{
    int count;
    int nbr;
    int len;
    int p;
    int sign;

    count = 0;
    nbr = va_arg(*arg, int);
    len = get_int_len(nbr);
    p = (flg.precision != -1) ? flg.precision : len;
    if (!flg.minus && sign != -1 && (!flg.zero || flg.width))
    {
        if (nbr < 0)
            count += apply_width_int(flg.width - p - 1);
        else
            count += apply_width_int(flg.width - p);
    }
    if (!flg.minus && flg.zero && flg.precision == -1)
    {
        count += apply_zero_int(flg.width - len);
    }
    apply_zero_int(p - len);
    ft_putnbr_fd(nbr, 1);
    if (flg.minus)
        count += apply_width_int(flg.width - p);
    return (count + p);
}

//int print_integer(va_list *arg, t_flags flg)
//{
//    int count;
//    int nbr;
//    int len;
//
//    count = 0;
//    nbr = va_arg(*arg, int);
//    len = get_int_len(nbr);
//    if (flg.precision != -1 && flg.precision && flg.width)
//        flg.width--;
//    if (flg.minus)
//    {
//        count += apply_zero(flg.precision, len);
//        ft_putnbr_fd(nbr, 1);
//        count += apply_width(flg.width, len);
//    }
//    else
//    {
//        if (flg.zero && flg.width)
//        {
//            flg.precision = flg.width;
//            flg.width = 0;
//        }
//        count += apply_width(flg.width, len);
//        count += apply_zero(flg.precision, len);
//        ft_putnbr_fd(nbr, 1);
//    }
//    count += len;
//    return (count);
//
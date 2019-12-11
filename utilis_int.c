/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:14:40 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/11 13:10:23 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     get_u_digits(unsigned int n)
{
    int len;
    unsigned int nb;

    len = 0;

    nb = n;
    while (nb > 9)
    {
        nb /= 10;
        len++;
    }
    if (nb <= 9)
        len++;
    return (len);
}

int     get_int_digits(int n)
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
    if (nb <= 9)
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

void    ft_putnbr_u(unsigned int n)
{
    unsigned int nb;

    nb = n;
    if (nb > 9)
        ft_putnbr_u(nb / 10);
    ft_putchar(nb % 10 + 48);
}
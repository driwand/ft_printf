/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:08:27 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/09 14:24:30 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putnbr(int n)
{
        unsigned int nb;

        if (n < 0)
        {
            ft_putchar('-');
            nb = -n;
        }
        else
            nb = n;
        if (nb > 9)
            ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + 48);
}

int print_integer(va_list *arg, t_flags flg)
{
    int count;
    int nbr;
    
    count = 0;
    nbr = va_arg(*arg, int);
    ft_putnbr(nbr);
    return (count);
}
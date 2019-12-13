/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:12:39 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/13 17:20:14 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	width_u_int(t_flags flg, int p, int *count)
{
	if (!flg.minus && flg.width)
	{
		if (!flg.zero)
			*count += apply_width_int(flg.width - p);
		else if (flg.precision > 0)
			*count += apply_width_int(flg.width - p);
		else if (flg.precision == 0)
			*count += apply_width_int(flg.width - p);
	}
}

static	void	manage_values(t_flags *flg, int *count, int *p, int nbr)
{
	int len;

	len = get_u_digits(nbr);
	*p = (flg->precision != -1 && flg->precision > len) ? flg->precision : len;
	if (!nbr && !flg->precision)
	{
		flg->width++;
		*count -= 1;
	}
}

int				print_unsigned(va_list *arg, t_flags flg)
{
	int			count;
	unsigned	nbr;
	int			len;
	int			p;

	count = 0;
	nbr = va_arg(*arg, int);
	len = get_u_digits(nbr);
	manage_values(&flg, &count, &p, nbr);
	width_u_int(flg, p, &count);
	if (!flg.minus && flg.zero && flg.precision == -1)
		count += apply_zero_int(flg.width - len);
	apply_zero_int(p - len);
	if ((flg.precision != 0 || nbr))
		ft_putnbr_u(nbr);
	if (flg.minus)
		count += apply_width_int(flg.width - p);
	return (count + p);
}

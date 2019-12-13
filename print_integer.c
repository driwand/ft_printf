/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:08:27 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/13 17:21:04 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		manage_int(int *nbr, int *len, int *p, t_flags *flg)
{
	int count;
	int sign;

	sign = 1;
	count = 0;
	*len = get_int_digits(*nbr);
	if (*nbr < 0)
	{
		*nbr *= -1;
		*len -= 1;
		sign = -1;
	}
	(*p) = (flg->precision != -1 && flg->precision > *len)
		? flg->precision : *len;
	if (sign < 0)
		flg->width--;
	if (!*nbr && !flg->precision)
	{
		flg->width++;
		count--;
	}
	return (count);
}

static	void	width_int(t_flags flg, int p, int *count)
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

static	void	manage_values(t_flags *flg, int nbr, int *sign)
{
	flg->precision = (nbr < 0 && flg->precision < 0 && flg->precision != -1)
		? flg->precision - 1 : flg->precision;
	if (nbr < 0 && flg->precision < 0 && flg->precision != -1)
		flg->precision = flg->width - 1;
	*sign = (nbr < 0) ? -1 : 1;
}

static	int		print_res_int(t_flags flg, int p, int len, int nbr)
{
	int count;

	count = 0;
	apply_zero_int(p - len);
	if ((flg.precision != 0 || nbr))
		ft_putnbr_fd(nbr, 1);
	if (flg.minus)
		count += apply_width_int(flg.width - p);
	return (count);
}

int				print_integer(va_list *arg, t_flags flg)
{
	int count;
	int nbr;
	int len;
	int p;
	int sign;

	count = 0;
	nbr = va_arg(*arg, int);
	manage_values(&flg, nbr, &sign);
	count += manage_int(&nbr, &len, &p, &flg);
	if (nbr < 0)
	{
		flg.width++;
		if (flg.precision != -1)
			flg.precision++;
	}
	width_int(flg, p, &count);
	if (sign < 0 && nbr != INT32_MIN)
		count += ft_putchar('-');
	if (!flg.minus && flg.zero && flg.precision == -1)
		count += apply_zero_int(flg.width - len);
	count += print_res_int(flg, p, len, nbr);
	if (nbr == INT32_MIN)
		count++;
	return (count + p);
}

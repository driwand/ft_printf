/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:37:42 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/14 13:50:14 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	to_upper_x(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

static	void	manage_width(t_flags flg, int *count, int p)
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

int				print_hexa(va_list *arg, t_flags flg)
{
	int					count;
	char				*res;
	int					len;
	int					p;
	unsigned int		nbr;

	nbr = va_arg(*arg, unsigned int);
	count = 0;
	res = (!nbr && !flg.precision) ? ft_strdup("") : to_hexa_uint(nbr);
	if (flg.specifier == 'X')
		to_upper_x(res);
	len = ft_strlen(res);
	p = (flg.precision != -1 && flg.precision > len)
		? flg.precision : len;
	manage_width(flg, &count, p);
	if (!flg.minus && flg.zero && flg.precision == -1)
		count += apply_zero_int(flg.width - len);
	count += apply_zero_int(p - len);
	count += ft_putstr(res);
	if (flg.minus)
		count += apply_width_int(flg.width - p);
	free(res);
	return (count);
}

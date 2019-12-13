/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:37:42 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/13 15:09:55 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	to_upper_x(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

int			print_hexa(va_list *arg, t_flags flg)
{
	int		count;
	char	*res;
	int		len;
	int p;
	
	count = 0;
	res = to_hexa_uint(va_arg(*arg, unsigned int));
	if (flg.specifier == 'X')
		to_upper_x(res);
	len = ft_strlen(res);
	p = (flg.precision != -1 && flg.precision > len)
		? flg.precision : len;
	if (!flg.minus && flg.width)
	{
		if (!flg.zero)
			count += apply_width_int(flg.width - p);
		else if (flg.precision > 0)
			count += apply_width_int(flg.width - p);
		else if (flg.precision == 0)
			count += apply_width_int(flg.width - p);
	}
	if (!flg.minus && flg.zero && flg.precision == -1)
		count += apply_zero_int(flg.width - len);
	count += apply_zero_int(p - len);
	count += ft_putstr(res);
	if (flg.minus)
		count += apply_width_int(flg.width - p);
	return (count);
}

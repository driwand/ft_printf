/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:37:42 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/11 17:37:55 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_hexa(va_list *arg, t_flags flg)
{
	int		count;
	int		nbr;
	char	*res;

	count = 0;
	nbr = va_arg(*arg, int);
	res = to_hexa_uint(nbr);
	if (flg.precision < 0)
		count += apply_zero_int(flg.width - ft_strlen(res));
	count += ft_putstr(res);
	return (count);
}
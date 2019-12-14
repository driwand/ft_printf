/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/14 12:24:10 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_result(const char *str, va_list *arg, t_flags flg)
{
	if (flg.specifier == 's')
		return (print_string(str, arg, flg));
	else if (flg.specifier == 'c' || is_not_specifier(flg.specifier))
		return (print_char(str, arg, flg));
	else if (flg.specifier == 'p')
		return (print_address(arg, flg));
	else if (flg.specifier == 'd' || flg.specifier == 'i')
		return (print_integer(arg, flg));
	else if (flg.specifier == 'x' || flg.specifier == 'X')
		return (print_hexa(arg, flg));
	else if (flg.specifier == 'u')
		return (print_unsigned(arg, flg));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;
	t_flags	flgs;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	count = 0;
	va_start(arg, str);
	while (i < len)
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else
		{
			initialize_flags(&flgs);
			get_flags(str + i, &arg, &flgs);
			count += printf_result(str + i + 1, &arg, flgs);
			i += flgs.skip_flags;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

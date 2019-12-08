/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 11:56:01 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/08 13:57:06 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		print_rest(const char *str, char *tmp, int len, t_flags flg)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (str[i] != flg.specifier)
	{
		if (flg.minus == 0)
		{
			count += apply_width(flg.width, len);
			if (flg.precision != -1)
				return (count + ft_putstr(tmp));
		}
		else
		{
			count += ft_putstr(tmp);
			count += apply_width(flg.width, len);
		}
		i = flg.skip_flags - 1;
	}
	if ((str[i] == 's' && i > 0 && !flg.minus) || (i == 0))
		count += ft_putstr(tmp);
	return (count);
}

int		print_string(const char *str, va_list *arg, t_flags flg)
{
	int		count;
	char	*tmp;
	int		len;

	count = 0;
	tmp = va_arg(*arg, char*);
	if (!tmp)
		tmp = "(null)";
	if (flg.precision >= 0)
	{
		tmp = apply_precision(tmp, flg.precision);
		free(tmp);
	}
	len = ft_strlen(tmp);
	count += print_rest(str, tmp, len, flg);
	return (count);
}


int		print_char(const char *str, va_list *arg, t_flags flg)
{
	int		count;
	char	c;
	int		i;

	i = 0;
	count = 0;
	c = (is_not_specifier(flg.specifier)) ? flg.specifier : va_arg(*arg, int);
	if (str[i] != flg.specifier)
	{
		if (flg.minus == 0)
		{
			count = (flg.zero) ? apply_zero(flg.width, 1)
				: apply_width(flg.width, 1);
			if (flg.precision != -1 || flg.zero)
			    return (count + ft_putchar(c));
		}
		else
		{
			count += ft_putchar(c);
			count += apply_width(flg.width, 1);
		}
		i++;
	}
	if (((str[i] == 'c' || c == 0 || is_not_specifier(flg.specifier)) && i > 0 && !flg.minus) || i == 0)
		count += ft_putchar(c);
	return (count);
}
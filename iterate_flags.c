/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:54:05 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/07 16:45:22 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_flags(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

int		is_specifier(char c)
{
	if (c == 'c' || c == 's')
		return (1);
	if (c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	initialize_flags(t_flags *flg)
{
	flg->minus = 0;
	flg->zero = 0;
	flg->width = 0;
	flg->precision = -1;
	flg->specifier = 0;
}

void	manage_flag(t_flags *flg, char c)
{
	if (flg->minus && flg->zero)
		flg->zero = 0;
	if (is_specifier(c))
		flg->specifier = c;
	if (flg->specifier == 'd' || flg->specifier == 'i' || flg->specifier == 'u'
			|| flg->specifier == 'x' || flg->specifier == 'x'
			|| flg->specifier == 's')
		flg->zero = 0;
	if (flg->width < 0)
	{
		flg->width *= -1;
		flg->minus = 1;
	}
	if (flg->precision >= 0 && flg->specifier == 'c')
		flg->precision = -1;
}

void	get_flags(const char *str, va_list *arg, t_flags *flg)
{
	int i;

	i = 0;
	while (!is_specifier(str[i]))
	{
		if (str[i] == '-')
			flg->minus = 1;
		else if (str[i] == '0')
			flg->zero = 1;
		else if (str[i] == '*' && (str[i - 1] == '%' || str[i - 1] == '-' ||
					str[i - 1] == '0'))
			flg->width = va_arg(*arg, int);
		else if (str[i] == '*' && str[i + 1] == '.')
			flg->width = va_arg(*arg, int);
		else if (str[i] == '*' && str[i - 1] == '.')
			flg->precision = va_arg(*arg, int);
		else if (str[i] == '.' && str[i + 1] != '*')
			flg->precision = ft_atoi(str + i + 1);
		else if (flg->width == 0 && (str[i - 1] == '%' || str[i - 1] == '-' ||
					str[i - 1] == '0'))
			flg->width = ft_atoi(str + i);
		i++;
	}
	flg->skip_flags = i;
	manage_flag(flg, str[i]);
}

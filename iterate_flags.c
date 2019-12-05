/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:54:05 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/05 16:15:27 by abkssiba         ###   ########.fr       */
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

void	inisilize_flags(t_flags *flg)
{
	flg->minus = 0;
	flg->zero = 0;
	flg->width = 0;
	flg->precision = -1;
	flg->specifier = 0;
	flg->asterisk_precision = 0;
	flg->asterisk_width = 0;
}

void	manage_flage(t_flags *flg, char c)
{
	if (flg->minus && flg->zero)
		flg->zero = 0;
	if (is_specifier(c))
		flg->specifier = c;
	if (flg->specifier == 'd' || flg->specifier == 'i' || flg->specifier == 'u'
		|| flg->specifier == 'x' || flg->specifier == 'x'
		|| flg->specifier == 's')
		flg->zero = 0;
}

void	get_flags(const char *str, t_flags *flg)
{
	int i;

	i = 0;
	inisilize_flags(flg);
	while (!is_specifier(str[i]) && str[i])
	{
		(str[i] == '-') ? flg->minus = 1 : 0;
        (str[i] == '0') ? flg->zero = 1 : 0;
        if (str[i] == '.')
		{
			if (str[i - 1] == '*')
				flg->asterisk_width = 1;
			if (str[i + 1] == '*')
				flg->asterisk_precision = 1;
			flg->precision = ft_atoi(str + i + 1); // if the presicion is negetive then ..
			i = (flg->precision == 0) ? i : i + skip_digits(&str[i + 1]);
		}
		if (flg->minus)
        	(flg->width == 0) ? flg->width = ft_atoi(str + i + 1) : 0;
		else
			(flg->width == 0) ? flg->width = ft_atoi(str + i) : 0;
		i++;
	}
	manage_flage(flg, str[i]);
}

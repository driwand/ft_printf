/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:07:53 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/08 12:09:48 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_zero(int width, int len)
{
	int count;

	count = 0;
	while (count < width - len)
	{
		ft_putchar_fd('0', 1);
		count++;
	}
	return (count);
}

char	*apply_precision(char *str, int pres)
{
	int		count;
	char	*g_tmp;

	count = 0;
	while (count < pres && str[count])
		count++;
	g_tmp = malloc(count + 1);
	pres = -1;
	while (++pres < count)
		g_tmp[pres] = str[pres];
	g_tmp[pres] = '\0';
	return (g_tmp);
}

int		apply_width(int width, int len)
{
	int count;

	count = 0;
	while (count < width - len)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	return (count);
}

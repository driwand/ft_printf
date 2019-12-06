/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/06 19:36:20 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char *g_tmp;

int count_bytes(const char *str, char parser)
{
	int i;
	int count;
	int count_pers;
	int j;
	int r;

	r = 0;
	i = 0;
	count = 0;
	count_pers = 0;
	while (str[i])
	{
		j = i;
		if (str[i] == '%' && str[i + 1] == parser)
			count++;
		if (str[i] == '%' && !ft_isalpha(str[i + 1]))
			count_pers++;
		i++;
	}
	count = ft_strlen(str) - ((count*2) + (count_pers/2));
	return (count);
}

int apply_minus()
{
	int count;

	count = 0;
	return (count);
}

int apply_width(int width, int len)
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

int apply_precision(char *str, int pres)
{
	int count;

	count = 0;
	while (count < pres && str[count])
		count++;
	g_tmp = malloc(count + 1);
	pres = -1;
	while (++pres < count)
		g_tmp[pres] = str[pres];
	g_tmp[pres] = '\0';
	return (count);
}

int print_string(const char *str, va_list *arg, t_flags flg)
{
	int count;
	int i;
	char *tmp;
	int len;

	i = 0;
	count = 0;
	
	if (flg.precision != -1)
	{
		apply_precision(va_arg(*arg, char*), flg.precision);
		tmp = g_tmp;
	}
	else
		tmp = va_arg(*arg, char*);
	len = ft_strlen(tmp);
    if (str[i] != flg.specifier)
    {
        if (flg.minus == 0)
		{
			count += apply_width(flg.width, len);
			if (flg.precision != -1)
				count += ft_putstr(tmp);
		}
		else
		{
			count += ft_putstr(tmp);
			count += apply_width(flg.width, len);
		}
        i++;
    }
	if ((str[i] == 's' && i > 0 && !flg.minus) || (i == 0))
		count += ft_putstr(tmp);
	return (count);
}

int printf_result(const char *str, va_list *arg, t_flags flg)
{
	if (flg.specifier == 's')
		return (print_string(str, arg, flg));
	return (0);
}


int ft_printf(const char *str, ...)
{
	int count;
	va_list arg;
	t_flags flgs;
	int start;
	int i;
	
	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else
		{
			inisilize_flags(&flgs);
			get_flags(str + i, &arg, &flgs);
			count += printf_result(str + i + 1, &arg, flgs);
			//printf("\nspecifier = %c, minus=%d zero=%d width=%d presicion=%d\n",
			//	flgs.specifier, flgs.minus, flgs.zero,flgs.width, flgs.precision);
			i += len_flags(str + i, flgs.specifier);
		}
		if (str[i])
			i++;
	}
	return (count);
}

int main()
{
	printf("%d\n", ft_printf("%-2.*s\n", -6,"hello"));
	printf("%d\n", printf("%-2.*s\n", -6,"hello"));
	//printf("%d\n",printf("hqello amal's %%%s%%%s call her %%%%%%%s\n" ,"mom","amal","dad"));
}
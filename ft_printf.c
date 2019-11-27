/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/11/25 20:03:54 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

void  ft_putstr(char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}

void  ft_get_rest(char *str, int start, int end)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
}


int ft_printf(const char * str, ...)
{
    va_list arg;
    int i;

    i = 0;
    va_start(arg, str);
    while (str[i])
    {
        while (str[i] == '%')
        {
            if (str[i + 1] == 's')
                ft_putstr_fd(va_arg(arg, char*), 1);
            else if (str[i + 1] == '%')
                ft_putchar_fd('%', 1);
            if (str[i + 1] == '%' || str[i + 1] == 's') {
                i = i + 2;
                continue;
            }
            i++;
        }
        if (str[i])
            ft_putchar_fd(str[i], 1);
        if(str[i])
            i++;
    }
    return (0);
}

int main()
{
	ft_printf("%lo");
}
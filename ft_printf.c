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

int ft_print_string(const char *str)
{
    va_list arg;
    int i;
    int count;
    char *tmp;
    int r;

    count = count_bytes(str, 's');
    i = 0;
    r = 0;
    va_start(arg, str);
    while (str[i])
    {
        while (str[i] == '%')
        {
            if (str[i + 1] == 's')
            {
                tmp = va_arg(arg, char*);
                count += ft_strlen(tmp);
                ft_putstr_fd(tmp, 1);
            }
            else if (str[i + 1] == '%')
                ft_putchar_fd('%', 1);
            else if (str[i + 1] != '%' || str[i + 1] != 's')
            {
                r++;
                ft_putchar_fd(str[i + 1], 1);
            }
            i += 2;
        }
        if (str[i])
            ft_putchar_fd(str[i], 1);
        if(str[i])
            i++;
    }
    va_end(arg);
    return (count - r);
}

int check_conversion(char c)
{
    if (c == '%' || c == 'c' || c == 's' || c == 'd')
        return (1);
    return (0);
}

int ft_printf(const char *str, ...)
{
    int count;
    va_list arg;
    int start;
    int i;

    i = 0;
    va_start(arg, str);
    while (str[i])
    {
        start = i;
        while (str[i] != '%')
        {
            ft_putchar_fd(str[i], 1);
        } 
        if (str[i] == '%')
        {
            count = ft_print_str(str, start, i);
            check_conversion(str[i + 1]);
        }
    }
}

int main()
{
	printf("%d\n",ft_printf("hello %s %d world","mom","amal","dad"));
    //printf("%d\n",printf("hqello amal's %%%s%%%s call her %%%%%%%s\n" ,"mom","amal","dad"));
}
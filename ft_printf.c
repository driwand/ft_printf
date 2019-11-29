/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/11/29 20:19:55 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

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

int ft_print_string(const char *str, ...)
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

int is_specifier(char c)
{
    if (c == 'c' || c == 's')
        return (1);
    if (c == 'p' || c == 'd' || c == 'i' || c == 'u'
        || c == 'x' || c == 'X')
        return (1);
    return (0);
}

void inisilize_flags(t_flags *flg)
{
    flg->minus = 0;
    flg->zero = 0;
    flg->width = 0;
    flg->precision = 0;
    flg->specifier = 0;
    flg->asterisk_precision = 0;
    flg->asterisk_width = 0;
}

void get_flags(const char *str, t_flags *flg) 
{
    int i;
    flg->width = 0;
    
    i = 0;
    inisilize_flags(flg);
    while (!is_specifier(str[i]))
    {
        if (str[i] == '-')
            flg->minus = 1;
        else if (str[i] == '0')
            flg->zero = 1;
        else if (str[i] == '.')
        {
            if (str[i - 1] == '*')
                flg->asterisk_width = 1;
            if (str[i + 1] == '*')
                flg->asterisk_precision = 1;
            flg->precision = ft_atoi(str + i + 1); // if the presicion is negetive then .. 
            i++;
        }
        else if (flg->width == 0)
            flg->width = ft_atoi(str + i);
        i++;
    }
    if (is_specifier(str[i]))
        flg->specifier = str[i];
    if (flg->specifier == 'd' || flg->specifier == 'i' || flg->specifier == 'u'
        || flg->specifier == 'x' || flg->specifier == 'x' || flg->specifier == 's')
        flg->zero = 0;
}

int ft_printf(const char *str, ...)
{
    int count;
    va_list arg;
    t_flags flgs;
    int start;
    int i;
    
    i = 0;
    va_start(arg, str);
    while (str[i])
    {
        if (str[i] != '%')
            ft_putchar_fd(str[i], 1);
        else
        {
            get_flags(str + i + 1, &flgs);
            
            //dont forget set flags to default
            break;
        }
        i++;
    }
    printf("\nspecifier = %c, minus=%d zero=%d width=%d presicion=%d\n",flgs.specifier, flgs.minus, flgs.zero,flgs.width, flgs.precision);
    return (0);
}

int main()
{
	printf("%d\n",ft_printf("hello %-22.15s %d world","mom","amal","dad"));
    //printf("%d\n",printf("hqello amal's %%%s%%%s call her %%%%%%%s\n" ,"mom","amal","dad"));
}
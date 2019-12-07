/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/07 18:01:11 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	printf_result(const char *str, va_list *arg, t_flags flg)
{
	if (flg.specifier == 's')
		return (print_string(str, arg, flg));
	else if (flg.specifier == 'c' || flg.specifier == '%')
		return (print_char(str, arg, flg));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;
	t_flags	flgs;
	int		i;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		// else if (str[i] == '%' && str[i + 1] == '%')
        // {
		//     count += ft_putchar('%');
		//     i += 1;
        // }
		else
		{
			initialize_flags(&flgs);
			get_flags(str + i, &arg, &flgs);
			count += printf_result(str + i + 1, &arg, flgs);
			i += flgs.skip_flags;
		}
		if (str[i])
			i++;
	}
	return (count);
}

int main()
{
	/* NULL */
	// printf("%d\n", ft_printf("%1.1s\n", NULL));
 	// printf("%d\n", printf("%1.1s\n", NULL));

	/* %% */
	// printf("%d\n", ft_printf("%%\n"));
	// printf("%d\n", printf("%%\n"));

	/* ultimate string */
 	// printf("%d\n", ft_printf("%*.*s %s,%-3.*s '%2c-%.c'\n", 6, 2, "hello" , NULL, 1,"ld", 'r', 0));
 	// printf("%d\n", printf("%*.*s %s,%-3.*s '%2c-%.c'\n", 6, 2, "hello", NULL, 1,"ld", 'r', 0));
 	printf("%d\n",ft_printf("hqello amal's %%%s%%%s call her %%%%%%%s\n" ,"mom","amal","dad"));
	printf("%d\n",printf("hqello amal's %%%s%%%s call her %%%%%%%s\n" ,"mom","amal","dad"));
}
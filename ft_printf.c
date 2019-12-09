/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/09 14:25:22 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	printf_result(const char *str, va_list *arg, t_flags flg)
{
	if (flg.specifier == 's')
		return (print_string(str, arg, flg));
	else if (flg.specifier == 'c' || is_not_specifier(flg.specifier))
		return (print_char(str, arg, flg));
	else if (flg.specifier == 'p')
		return	(print_address(arg, flg));
	else if (flg.specifier == 'd' || flg.specifier == 'd')
		return	(print_integer(arg, flg));
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
	return (count);
}

int main()
{
	int *p;
	char *str = "hello";

	printf("%d\n", ft_printf("%d\n", 22));
	//printf("%d\n", printf("%d\n", 22));

	// ft_printf("%*2s\n", 2, "h");
	// printf("%*2s\n", 2, "h");

	// printf("\n%d\n", ft_printf("%*w", 12));
	// printf("\n%d\n", printf("%*w", 12));
	
	// printf("\n%d\n", ft_printf("%p", -12));
	// printf("\n%d\n", printf("%p", -12));

	// printf("\n%d\n", ft_printf("%5u*w", -12));
	// printf("\n%d\n", printf("%5u*w", -12));

	// printf("\n%d\n", ft_printf("%*.*s", -15, 0, NULL));
	// printf("\n%d\n", printf("%*.*s", -15, 0, NULL));
	
	/* normal */
	// printf("%d\n", ft_printf("%*.*s\n", 6, -2, "hello"));
 	// printf("%d\n", printf("%*.*s\n", 6, -2, "hello"));

	/* NULL */
	// printf("%d\n", ft_printf("%1.1s\n", NULL));
 	// printf("%d\n", printf("%1.1s\n", NULL));

	/* %% */
	// printf("%d\n", ft_printf("%-5%%02%\n"));
	// printf("%d\n", printf("%-5%%02%\n"));

	/* address */
	// printf("%d\n", ft_printf("%*p\n", -16, &p));
	// printf("%d\n", printf("%*p\n", -16, &p));

	/* ultimate string */
 	// printf("%d\n", ft_printf("%*.*s %s,%-3.*s '%-2c-%.c'|%.%%p|%s<%0*%>\n", 6, 2, str , NULL, 1,"ld", 'r', 0, &p,"wow", 2));
 	// printf("%d\n", printf("%*.*s %s,%-3.*s '%-2c-%.c'|%.%%p|%s<%0*%>\n", 6, 2, str, NULL, 1,"ld", 'r', 0, &p, "wow", 2));
 	// printf("%d\n",ft_printf("hqello amal's %%%s%%%s call her %02%%-2%%%%s\n" ,"mom","amal","dad"));
	// printf("%d\n",printf("hqello amal's %%%s%%%s call her %02%%-2%%%%s\n" ,"mom","amal","dad"));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:04:28 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/10 21:11:27 by abkssiba         ###   ########.fr       */
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
	else if (flg.specifier == 'd' || flg.specifier == 'i'
		|| flg.specifier == 'u')
		return	(print_integer(arg, flg));
	else if (flg.specifier == 'x' || flg.specifier == 'X')
		return (print_hexa(arg, flg));
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

	/* ----------------------     integer     ---------------------- */
	
	// printf("%d\n", ft_printf("%-*.*d\n", 4,3,1));
	// printf("%d\n", printf("%-*.*d\n",4,3, 1));
	
	// printf("%d\n", ft_printf("%2.04d\n", 1));
	// printf("%d\n", printf("%2.04d\n", 1));

	// printf("%d\n", ft_printf("%02.04d\n", 1));
	// printf("%d\n", printf("%02.04d\n", 1));

	// printf("\n%d\n", ft_printf("%05d", -12));
	// printf("\n%d\n", printf("%05d", -12));

	// printf("\n%d\n", ft_printf("%05d", 12));
	// printf("\n%d\n", printf("%05d", 12));

	// printf("%d\n", ft_printf("%*.*d\n", 10, 3, 32));
	// printf("%d\n", printf("%*.*d\n", 10, 3, 32));

	// printf("%d\n", ft_printf("%0*.*d\n", 10,5, -32));
	// printf("%d\n", printf("%0*.*d\n", 10,5, -32));

	// printf("%d\n", ft_printf("%*.05d\n", 10, 32));
	// printf("%d\n", printf("%*.05d\n", 10, 32));
	
	// printf("%d\n", ft_printf("%*.*d\n", 10, 3, 32));
	// printf("%d\n", printf("%*.*d\n", 10, 3, 32));
			
	// printf("%d\n", ft_printf("%20d\n", INT32_MAX + 2)); //error
	// printf("%d\n", printf("%20d\n", INT32_MAX + 2));

	// printf("%d\n", ft_printf("%4d\n", 2));
	// printf("%d\n", printf("%4d\n", 2));

	// printf("%d\n", ft_printf("%0-4d\n", 2));
	// printf("%d\n", printf("%0-4d\n", 2));

	// printf("%d\n", ft_printf("%s\n", str));
	// printf("%d\n", printf("%s\n", str));

	// printf("%d\n", ft_printf("%-.3d\n",-2));
	// printf("%d\n", printf("%-.3d\n",-2));

	// printf("%d\n", ft_printf("%05.3d\n", 12));
	// printf("%d\n", printf("%05.3d\n", 12));
	
    // printf("%d\n", ft_printf("%4.2d\n", 1));
    // printf("%d\n", printf("%4.2d\n", 1));

	// printf("%d\n", ft_printf("%*.*d\n", 4, 4, 1));
	// printf("%d\n", printf("%*.*d\n", 4, 4, 1));

	/* ----------------------       hexa      ---------------------- */
	
	// printf("%d\n", ft_printf("%04.*x\n",2, -15));
	// printf("%d\n", printf("%05.*x\n",2, -15));


	/* ----------------------      huh??      ---------------------- */
	
	// printf("\n%d\n", ft_printf("%5*w", -12));
	// printf("\n%d\n", printf("%5*w", -12));

	// printf("\n%d\n", ft_printf("%*w", 12));
	// printf("\n%d\n", printf("%*w", 12));
	
	/* ----------------------     normal 	  ---------------------- */
	
	// printf("%d\n", ft_printf("%*.*s\n", 6, 2, "hello"));
 	// printf("%d\n", printf("%*.*s\n", 6, 2, "hello"));

	// ft_printf("%*2s\n", 2, "h");
	// printf("%*2s\n", 2, "h");

	// ft_printf("%*s\n", 0, "h");
	// printf("%*s\n", 0, "h");
	
	/* ----------------------      NULL       ---------------------- */
	
	// printf("%d\n", ft_printf("%1.1s\n", NULL));
 	// printf("%d\n", printf("%1.1s\n", NULL));

	// printf("\n%d\n", ft_printf("%*.*s", -15, 0, NULL));
	// printf("\n%d\n", printf("%*.*s", -15, 0, NULL));
	
	/* ----------------------       %% 	     ---------------------- */
	
	// printf("%d\n", ft_printf("%-5%%02%\n"));
	// printf("%d\n", printf("%-5%%02%\n"));

	/* ----------------------    address     ---------------------- */
	
	// printf("%d\n", ft_printf("%*p\n", -16, &p));
	// printf("%d\n", printf("%*p\n", -16, &p));

	// printf("\n%d\n", ft_printf("%p", -12));
	// printf("\n%d\n", printf("%p", -12));

	/* ---------------------- ultimate string ---------------------- */
	
 	// printf("%d\n", ft_printf("%*.*s %s,%-3.*s '%-2c-%.c'|%.%%p|%s<%0*%>\n", 6, 2, str , NULL, 1,"ld", 'r', 0, &p,"wow", 2));
 	// printf("%d\n", printf("%*.*s %s,%-3.*s '%-2c-%.c'|%.%%p|%s<%0*%>\n", 6, 2, str, NULL, 1,"ld", 'r', 0, &p, "wow", 2));
	 
	// printf("%d\n",ft_printf("hqello amal's %%%s%%%s call her %02%%-2%%%%s\n" ,"mom","amal","dad"));
	// printf("%d\n",printf("hqello amal's %%%s%%%s call her %02%%-2%%%%s\n" ,"mom","amal","dad"));
}
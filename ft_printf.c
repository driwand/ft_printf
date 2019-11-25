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
#include "libft/libft.h"

int    ft_get_arr(const char *str, char c)
{
	int             count;
	int             i;
	int             j;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = i;
		while (str[j] != c && str[j] != '\0')
			j++;
		if (j > i)
		{
			count++;
			i = j;
			continue ;
		}
		i++;
	}
	return (count);
}

int ft_printf(const char *s, ...)
{
	int count;
	va_list arguments;

	
	if (!s)
		return (-1);
	count = ft_get_arr(s, '%');
	printf("%d", count);
	ft_putstr_fd((char *)s, 1);
	return (0);
}

int main()
{
	printf("huh%%");
    return (0);
}

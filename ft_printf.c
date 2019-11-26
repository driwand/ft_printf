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

char *new_str(char *old, int index, char *str, int len)
{
	char *new;
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	new = malloc(len);
	i = 0;

	while (index--)
	{
		new[i] = old[i];
		i++;
	}
	printf("%d %d %d %s | %s | %s\n",len, i, index, old, new, str);
	while (i < len)
	{
		new[i] = str[j];
		i++;
		j++;
	}
	printf("%c %d %d %c %d\n", new[len - 1], len , j, old[i], i);
	k = 3;
	while (j < len && k > 0)
	{
		new[len - k] = old[j];
		k--;
		j++;
	}
	printf("%d %d %d %s | %s | %s\n",len, i, index, old, new, str);
	new[len] = '\0';
	return (new);
}

int ft_printf(const char *s,...)
{
	int count;
	int i;
	char *str;
	va_list arguments;
	int len;
	char *tmp;
	int len_s;
	char *new;

	i = 0;
	if (!s)
		return (-1);
	len = 0;
	len_s = ft_strlen(s);
	count = ft_get_arr(s, '%');
	if (count == 0)
		ft_putstr_fd((char *)s, 1);
	else
	{
		va_start(arguments, s);
		while (s[i])
		{
			if (s[i] == '%')
			{
				if (s[i + 1] == 's')
					str = va_arg(arguments, char*);
				len += ft_strlen(str);
				tmp = malloc(len + len_s + 1);
				if (!new)
				{
					new = new_str((char*)s, i, str, len + len_s + 1 - 2);
					i++;
					//printf("%s\n", new);
					continue ;
				}
				new = new_str(new, i, str, len + len_s + 1);
			}
			i++;	
		}
	}
	va_end(arguments);
	return (0);
}

int main()
{
	ft_printf("hut %s az", "wxc");
    return (0);
}

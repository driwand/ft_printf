/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:42:37 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/09 13:24:51 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char	*to_hexa_uint(uintmax_t nb)
{
	char		*res;
	int			i;
	uintmax_t	j;

	i = 0;
	j = nb;
	while (j >= 16)
	{
		j /= 16;
		i++;
	}
	res = (char *)malloc(i + 1);
	res[i] = '\0';
	while (i >= 0)
	{
		j = nb % 16;
		if (j >= 10)
			res[i] = j - 10 + 'a';
		else
			res[i] = j + '0';
		nb /= 16;
		i--;
	}
	return (res);
}

char	*to_hexa(int nb)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = nb;
	while (j >= 16)
	{
		j /= 16;
		i++;
	}
	res = (char *)malloc(i + 1);
	res[i] = '\0';
	while (i >= 0)
	{
		j = nb % 16;
		if (j >= 10)
			res[i] = j - 10 + 'a';
		else
			res[i] = j + '0';
		nb /= 16;
		i--;
	}
	return (res);
}

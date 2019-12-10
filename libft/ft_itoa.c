/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:28:08 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/10 18:28:39 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_len(long int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void		ft_fill(char *str, long int n, int sign, int len)
{
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1 && !++len)
		str[len] = '-';
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		last;
	int		sign;

	sign = 1;
	len = ft_get_len(n);
	last = len;
	if (n == 0)
		return (ft_strdup("0"));
	str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_fill(str, n, sign, len);
	str[last] = '\0';
	return (str);
}

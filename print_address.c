/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:06:26 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/13 15:36:56 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		print_resrt(const char *str, char *tmp, int len, t_flags flg)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (flg.minus == 0)
	{
		count += apply_width(flg.width, len);
		if (flg.precision != -1)
			count += ft_putstr(tmp);
	}
	else
	{
		count += ft_putstr(tmp);
		count += apply_width(flg.width, len);
		i++;
	}
	if ((str[i] == 'p' && !flg.minus))
		return (count + ft_putstr(tmp));
	else if (i == 0)
		return (count + ft_putstr(tmp));
	return (count);
}

static	int		print_result(const char *str, char *res, t_flags flg)
{
	int		count;
	char	*tmp;
	int		len;

	count = 0;
	tmp = res;
	len = ft_strlen(tmp);
	count += print_resrt(str, tmp, len, flg);
	free(res);
	return (count);
}

static	char	*create_adr(char *str)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 2;
	len = ft_strlen(str);
	if (!(res = (char*)malloc(len + 3)))
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	while (i < len + 2)
	{
		res[i] = str[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int				print_address(va_list *arg, t_flags flg)
{
	uintmax_t	tmp;
	char		*res;
	char		*tmp_s;

	tmp = va_arg(*arg, uintmax_t);
	res = to_hexa_uint((uintmax_t)tmp);
	tmp_s = res;
	res = create_adr(res);
	free(tmp_s);
	return (print_result(res, res, flg));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:25:26 by abkssiba          #+#    #+#             */
/*   Updated: 2019/10/23 16:21:12 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char *temp;

	temp = s;
	if (!s)
		return ;
	ft_putstr_fd(temp, fd);
	ft_putchar_fd('\n', fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:35:51 by abkssiba          #+#    #+#             */
/*   Updated: 2019/10/19 12:18:29 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int len_dest;
	int len_src;
	int i;

	i = 0;
	len_src = ft_strlen(s2);
	len_dest = ft_strlen(s1);
	while (i < len_src)
	{
		s1[len_dest] = s2[i];
		i++;
		len_dest++;
	}
	s1[len_dest] = '\0';
	return (s1);
}

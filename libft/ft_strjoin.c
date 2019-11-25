/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:36:02 by abkssiba          #+#    #+#             */
/*   Updated: 2019/10/23 16:15:32 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_d;
	size_t	len_s;

	if (!s2 || !s1)
		return (NULL);
	len_d = ft_strlen(s1);
	len_s = ft_strlen(s2);
	str = (char*)ft_calloc(len_d + len_s + 1, sizeof(char*));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, len_s + len_d);
	ft_memmove(str + len_d, s2, len_s);
	return (str);
}

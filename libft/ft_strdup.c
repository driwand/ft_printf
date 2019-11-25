/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:46:20 by abkssiba          #+#    #+#             */
/*   Updated: 2019/10/18 12:47:38 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
	{
		ft_memcpy(str, s1, len);
		str[len] = 0;
		return (str);
	}
	return (NULL);
}

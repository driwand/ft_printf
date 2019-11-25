/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:25:09 by abkssiba          #+#    #+#             */
/*   Updated: 2019/11/05 13:50:45 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	if (!*str2)
		return (str1);
	if (!str1 && !len)
		return (0);
	while (str1[i])
	{
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] && i + j < len)
			j++;
		if (!str2[j])
			return (str1 + i);
		i++;
	}
	return (NULL);
}

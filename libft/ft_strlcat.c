/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:31:27 by abkssiba          #+#    #+#             */
/*   Updated: 2019/11/02 18:29:47 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	lend;
	int		i;

	i = 0;
	len_src = ft_strlen(src);
	if (!dest && size == 0)
		return (len_src);
	len_dest = ft_strlen(dest);
	lend = len_dest;
	if (size <= len_dest)
		return (size + len_src);
	else
	{
		while (src[i] && lend < size - 1)
			dest[lend++] = src[i++];
		dest[lend] = '\0';
		return (len_dest + len_src);
	}
}

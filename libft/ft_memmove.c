/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:17:43 by abkssiba          #+#    #+#             */
/*   Updated: 2019/11/05 13:33:32 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (len--)
		{
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}

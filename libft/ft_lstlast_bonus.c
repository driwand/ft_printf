/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:02:16 by abkssiba          #+#    #+#             */
/*   Updated: 2019/10/29 11:21:42 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	int		len;
	t_list	*last;

	if (!lst)
		return (NULL);
	len = ft_lstsize(lst);
	i = 0;
	while (i < len - 1)
	{
		lst = lst->next;
		i++;
	}
	last = lst;
	return (last);
}

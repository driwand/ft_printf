/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:16:08 by abkssiba          #+#    #+#             */
/*   Updated: 2019/11/29 20:06:34 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
    int zero;
    int minus;
    int width;
    int precision;
    int asterisk_width;
    int asterisk_precision;
    char specifier;
}t_flags;


int ft_printf(const char*str, ...);


#endif
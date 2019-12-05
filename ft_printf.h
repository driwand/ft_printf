/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:16:08 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/05 15:04:43 by abkssiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct	s_flags
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	int		asterisk_width;
	int		asterisk_precision;
	char	specifier;
}				t_flags;

int				ft_printf(const char*str, ...);
int				len_flags(const char *str, char c);
int				is_specifier(char c);
void			inisilize_flags(t_flags *flg);
void			manage_flage(t_flags *flg, char c);
void			get_flags(const char *str, t_flags *flg);
int				ft_putstr(char *str);
int				ft_putchar(char c);
int				skip_digits(const char *str);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkssiba <abkssiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:16:08 by abkssiba          #+#    #+#             */
/*   Updated: 2019/12/09 14:22:32 by abkssiba         ###   ########.fr       */
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
	char	specifier;
	int		skip_flags;
}				t_flags;

int				ft_printf(const char*str, ...);
int				len_flags(const char *str, char c);
int				is_specifier(char c);
void			initialize_flags(t_flags *flg);
void			get_flags(const char *str, va_list *arg, t_flags *flg);
int				ft_putstr(char *str);
int				ft_putchar(char c);
int             is_not_specifier(char c);
int				skip_digits(const char *str);
int				print_string(const char *str, va_list *arg, t_flags flg);
int				print_char(const char *str, va_list *arg, t_flags flg);
int				print_address(va_list *arg, t_flags flg);
int				print_nonflag(t_flags flg);
int				print_integer(va_list *arg, t_flags flg);
char			*to_hexa_uint(uintmax_t nb);
char			*to_hexa(int nb);
int				apply_width(int width, int len);
char			*apply_precision(char *str, int pres);
int				apply_zero(int width, int len);
#endif

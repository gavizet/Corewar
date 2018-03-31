/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:18:35 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/02 11:23:23 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

# define M_H 1
# define M_HH 5
# define M_L 2
# define M_LL 6
# define M_J 3
# define M_Z 4

typedef	struct		s_flags
{
	int				blank;
	int				minus;
	int				plus;
	int				diez;
	int				zero;
}					t_flags;

typedef	struct		s_format
{
	t_flags			flags;
	int				width;
	int				precision;
	int				modifier;
	char			type;
}					t_format;

int					is_type(char c);
int					is_flags(char c);

int					aff_hexa(t_format *fmt);
int					aff_zero(t_format *fmt);
int					aff_blank(t_format *fmt);
int					putstr_wsign(char *str, t_format *fmt);
int					putstr_preci(char *str, t_format *fmt);

int					ft_printf(const char *format, ...);
int					launch(char **addr_str, va_list args);

char				*convert_sint(t_format *fmt, va_list args);
char				*convert_unsint(t_format *fmt, va_list args, int base);

int					apply_flag_d(t_format *fmt, va_list args);
int					apply_flag_x(t_format *fmt, va_list args);
int					apply_flag_o(t_format *fmt, va_list args);
int					apply_flag_u(t_format *fmt, va_list args);
int					apply_flag_b(t_format *fmt, va_list args);
int					apply_flag_p(t_format *fmt, va_list args);
int					apply_flag_s(t_format *fmt, va_list args);
int					apply_flag_c(t_format *fmt, va_list args);
int					apply_flag_pour(t_format *fmt, va_list args);
int					apply_flag_wstr(t_format *fmt, va_list args);
int					apply_flag_wchar(t_format *fmt, va_list args);
int					apply_flag_percent(t_format *fmt, char **str);

int					check_conversion_dou(t_format *fmt, va_list args);
int					check_conversion_xb(t_format *fmt, va_list args);
int					check_conversion_sc(t_format *fmt, va_list args,
					char **addr_str);
void				check_flag(char **addr_str, t_format *addr_format);
void				check_width(char **addr_str, t_format *addr_format);
void				check_precision(char **addr_str, t_format *addr_format);
void				check_modifier(char **addr_str, t_format *addr_format);

#endif

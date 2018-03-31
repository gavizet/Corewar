/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:07:46 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/02 11:01:27 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_flag_d(t_format *fmt, char *str, int len)
{
	int		ret_val;

	ret_val = 0;
	if (fmt->precision != -1 && fmt->precision > len)
		fmt->precision -= len;
	if (fmt->flags.plus == 1 || str[0] == '-' || fmt->flags.blank == 1)
		fmt->width--;
	if (fmt->flags.blank == 1)
		ret_val += write(1, " ", 1);
	if (str[0] == '-' && fmt->flags.zero == 1)
		ft_putchar('-');
	if (fmt->flags.plus == 1 && str[0] != '-' && fmt->flags.zero == 1)
		ret_val += write(1, "+", 1);
	if (fmt->flags.minus == 0)
		ret_val += aff_blank(fmt);
	if (str[0] == '-' && fmt->flags.zero == 0)
		ft_putchar('-');
	if (fmt->flags.plus == 1 && str[0] != '-' && fmt->flags.zero == 0)
		ret_val += write(1, "+", 1);
	ret_val += (fmt->precision == 0 && str[0] == '0') ? 0 :
		aff_zero(fmt) + putstr_wsign(str, fmt);
	if (fmt->flags.minus == 1)
		ret_val += aff_blank(fmt);
	ft_strdel(&str);
	return (ret_val);
}

int			apply_flag_d(t_format *fmt, va_list args)
{
	int		len;
	char	*str;

	str = convert_sint(fmt, args);
	len = str[0] != '-' ? ft_strlen(str) : ft_strlen(str) - 1;
	if (fmt->precision != -1 || fmt->flags.minus == 1)
		fmt->flags.zero = 0;
	if ((str[0] == '-' || fmt->flags.plus == 1 || fmt->width > len) &&
			fmt->flags.blank == 1 && fmt->flags.zero == 0)
		fmt->flags.blank = 0;
	if (fmt->width != 0 && fmt->width <= len)
		fmt->width = 0;
	if (fmt->width != 0 && fmt->precision == -1 && fmt->width > len)
		fmt->width -= len;
	if (fmt->width != 0 && fmt->precision != -1 && fmt->width > len)
		fmt->width -= fmt->precision;
	if (fmt->precision == 0 && str[0] == '0')
		fmt->width += 1;
	if (fmt->precision != -1 && fmt->precision <= len)
	{
		fmt->width -= (len - fmt->precision);
		fmt->precision = 0;
	}
	return (print_flag_d(fmt, str, len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:04:08 by gavizet           #+#    #+#             */
/*   Updated: 2018/01/19 14:36:55 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			len_wchar(wchar_t c, int len)
{
	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else if (c <= 0x10FFFF)
		len = 4;
	else
		len = 0;
	return (len);
}

int			apply_flag_wchar(t_format *fmt, va_list args)
{
	wchar_t	c;
	int		len;
	int		ret_val;

	len = 0;
	ret_val = 0;
	c = (wchar_t)va_arg(args, wint_t);
	len = len_wchar(c, len);
	if (fmt->flags.minus == 1 && fmt->flags.zero == 1)
		fmt->flags.zero = 0;
	if (fmt->width != 0 && fmt->precision == -1 && fmt->width <= len)
		fmt->width = 0;
	if (fmt->width != 0 && fmt->precision == -1 && fmt->width > len)
		fmt->width -= len;
	if (fmt->width != 0 && fmt->precision != -1)
		fmt->width -= len;
	if (fmt->precision != -1 && fmt->precision >= len)
		fmt->precision = len;
	if (fmt->flags.minus == 0)
		ret_val += aff_blank(fmt);
	ft_putwchar(c);
	if (fmt->flags.minus == 1)
		ret_val += aff_blank(fmt);
	return (ret_val + len);
}

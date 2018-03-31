/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:49:06 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/02 11:02:09 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_flag_p(t_format *fmt, char *str)
{
	int		ret_val;

	ret_val = 2;
	fmt->width -= 2;
	if (fmt->flags.zero == 1)
		ft_putstr("0x");
	if (fmt->flags.minus == 0)
		ret_val += aff_blank(fmt);
	if (fmt->flags.zero == 0)
		ft_putstr("0x");
	ret_val += aff_zero(fmt) + putstr_wsign(str, fmt);
	if (fmt->flags.minus == 1)
		ret_val += aff_blank(fmt);
	ft_strdel(&str);
	return (ret_val);
}

int			apply_flag_p(t_format *fmt, va_list args)
{
	int		len;
	char	*str;

	str = convert_unsint(fmt, args, 16);
	len = ft_strlen(str);
	if (fmt->precision == 0 && str[0] == '0')
	{
		ft_putstr("0x");
		return (2);
	}
	if (fmt->width != 0 && fmt->width <= len)
		fmt->width = 0;
	if (fmt->width != 0 && fmt->precision == -1 && fmt->width > len)
		fmt->width -= len;
	if (fmt->width != 0 && fmt->precision != -1 && fmt->width > len)
		fmt->width -= fmt->precision;
	if (fmt->precision != -1 && fmt->precision <= len)
	{
		fmt->width -= (len - fmt->precision);
		fmt->precision = 0;
	}
	if (fmt->precision != -1 && fmt->precision > len)
		fmt->precision -= len;
	return (print_flag_p(fmt, str));
}

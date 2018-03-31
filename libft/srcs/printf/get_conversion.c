/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:22 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/02 10:59:09 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_conversion_dou(t_format *fmt, va_list args)
{
	if (fmt->type == 'd' || fmt->type == 'i')
		return (apply_flag_d(fmt, args));
	if (fmt->type == 'D')
	{
		fmt->modifier = 2;
		return (apply_flag_d(fmt, args));
	}
	if (fmt->type == 'o')
		return (apply_flag_o(fmt, args));
	if (fmt->type == 'O')
	{
		fmt->modifier = 2;
		return (apply_flag_o(fmt, args));
	}
	if (fmt->type == 'u')
		return (apply_flag_u(fmt, args));
	if (fmt->type == 'U')
	{
		fmt->modifier = 2;
		return (apply_flag_u(fmt, args));
	}
	else
		return (0);
}

int		check_conversion_xb(t_format *fmt, va_list args)
{
	if (fmt->type == 'x')
		return (apply_flag_x(fmt, args));
	if (fmt->type == 'X')
		return (apply_flag_x(fmt, args));
	if (fmt->type == 'b')
		return (apply_flag_b(fmt, args));
	if (fmt->type == 'B')
	{
		fmt->modifier = 2;
		return (apply_flag_b(fmt, args));
	}
	if (fmt->type == 'p')
	{
		fmt->modifier = 4;
		return (apply_flag_p(fmt, args));
	}
	else
		return (0);
}

int		check_conversion_sc(t_format *fmt, va_list args, char **addr_str)
{
	if (fmt->type == 's')
	{
		if (fmt->modifier == 2)
			return (apply_flag_wstr(fmt, args));
		else
			return (apply_flag_s(fmt, args));
	}
	if (fmt->type == 'S')
		return (apply_flag_wstr(fmt, args));
	if (fmt->type == 'c')
	{
		if (fmt->modifier == 2)
			return (apply_flag_wchar(fmt, args));
		else
			return (apply_flag_c(fmt, args));
	}
	if (fmt->type == 'C')
		return (apply_flag_wchar(fmt, args));
	if (fmt->type == '%')
		return (apply_flag_percent(fmt, addr_str));
	else
		return (0);
}

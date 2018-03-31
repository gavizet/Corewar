/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argirin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:06:49 by argirin           #+#    #+#             */
/*   Updated: 2017/06/02 10:58:38 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		launch(char **addr_str, va_list args)
{
	int			i;
	t_format	format;

	i = 0;
	check_flag(addr_str, &format);
	check_width(addr_str, &format);
	check_precision(addr_str, &format);
	check_modifier(addr_str, &format);
	if ((is_type(**addr_str)) == 1)
		format.type = **addr_str;
	else
		return (apply_flag_percent(&format, addr_str));
	i += check_conversion_dou(&format, args);
	i += check_conversion_xb(&format, args);
	i += check_conversion_sc(&format, args, addr_str);
	return (i);
}

int		ft_vfprintf(const char *format, va_list args)
{
	int			ret;

	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (ret);
			ret += launch((char**)&format, args);
		}
		else
		{
			ret++;
			ft_putchar(*format);
		}
		format++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret_val;

	va_start(args, format);
	ret_val = ft_vfprintf(format, args);
	va_end(args);
	return (ret_val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:15:37 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/02 11:02:59 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_width(char **addr_str, t_format *addr_format)
{
	addr_format->width = ft_atoi(*addr_str);
	while (**addr_str >= '0' && **addr_str <= '9')
		(*addr_str)++;
}

void	check_precision(char **addr_str, t_format *addr_format)
{
	if (**addr_str == '.')
	{
		(*addr_str)++;
		if (**addr_str >= '1' && **addr_str <= '9')
			addr_format->precision = ft_atoi(*addr_str);
		else
			addr_format->precision = 0;
		while (**addr_str >= '0' && **addr_str <= '9')
			(*addr_str)++;
	}
	else
		addr_format->precision = -1;
}

void	check_flag(char **addr_str, t_format *format)
{
	format->flags.blank = 0;
	format->flags.minus = 0;
	format->flags.plus = 0;
	format->flags.diez = 0;
	format->flags.zero = 0;
	while (is_flags(**addr_str))
	{
		if (**addr_str == '+')
			format->flags.plus = 1;
		else if (**addr_str == ' ' && format->flags.plus == 0)
			format->flags.blank = 1;
		else if (**addr_str == '-')
			format->flags.minus = 1;
		else if (**addr_str == '#')
			format->flags.diez = 1;
		else if (**addr_str == '0')
			format->flags.zero = 1;
		(*addr_str)++;
	}
}

void	check_modifier(char **addr_str, t_format *addr_format)
{
	addr_format->modifier = 0;
	addr_format->modifier = (!ft_strncmp(*addr_str, "h", 1)) ?
		M_H : addr_format->modifier;
	addr_format->modifier = (!ft_strncmp(*addr_str, "hh", 2)) ?
		M_HH : addr_format->modifier;
	addr_format->modifier = (!ft_strncmp(*addr_str, "l", 1)) ?
		M_L : addr_format->modifier;
	addr_format->modifier = (!ft_strncmp(*addr_str, "ll", 2)) ?
		M_LL : addr_format->modifier;
	addr_format->modifier = (!ft_strncmp(*addr_str, "j", 1)) ?
		M_J : addr_format->modifier;
	addr_format->modifier = (!ft_strncmp(*addr_str, "z", 1)) ?
		M_Z : addr_format->modifier;
	if (addr_format->modifier >= M_HH)
		(*addr_str) += 2;
	else if (addr_format->modifier > 0)
		(*addr_str)++;
}

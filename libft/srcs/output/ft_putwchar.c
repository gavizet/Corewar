/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:19:40 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/22 23:16:22 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwchar(wchar_t str)
{
	if (str <= 0x7F)
		ft_putchar(str);
	else if (str <= 0x7FF)
	{
		ft_putchar((str >> 6) + 0xC0);
		ft_putchar((str & 0x3f) + 0x80);
	}
	else if (str <= 0xFFFF)
	{
		ft_putchar((str >> 12) + 0xE0);
		ft_putchar(((str >> 6) & 0x3F) + 0x80);
		ft_putchar((str & 0x3F) + 0x80);
	}
	else if (str <= 0x10FFFF)
	{
		ft_putchar((str >> 18) + 0xF0);
		ft_putchar(((str >> 12) & 0x3F) + 0x80);
		ft_putchar(((str >> 6) & 0x3F) + 0x80);
		ft_putchar((str & 0x3F) + 0x80);
	}
}

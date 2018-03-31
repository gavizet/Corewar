/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 20:36:30 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/22 23:02:07 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calc_wstrlen(wchar_t *str, int precision, int i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (ft_calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (ft_calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (ft_calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (ft_calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

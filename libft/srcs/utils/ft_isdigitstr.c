/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 23:30:10 by rlangeoi          #+#    #+#             */
/*   Updated: 2017/03/19 23:33:17 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigitstr(const char *str)
{
	if (!str)
		return (-1);
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

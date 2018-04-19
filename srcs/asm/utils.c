/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 12:15:31 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/19 15:11:33 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_empty_char(int c)
{
	if (c == (int)' ' || c == (int)'\t' || c == (int)'\v' || c == (int)'\r'
			|| c == (int)'\f' || c == (int)'\n')
		return (1);
	return (0);
}

int		line_is_comment(char *str)
{
	int	i;

	i = 0;
	while (is_empty_char(str[i]))
		i++;
	if (str[i] != '#' && str[i] != ';')
		return (1);
	return (0);
}

int		line_is_empty(char *str)
{
	int	i;

	i = 0;
	if (!str || !(*str))
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\v' || str[i] != '\r'
				|| str[i] != '\f' || str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

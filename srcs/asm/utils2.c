/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:17:25 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/21 18:26:49 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (-1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	return (1);
}

int		is_valid_instr(char *instr, t_line *line)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((ft_strcmp(instr, OP_TAB(i).name)) == 0)
		{
			line->op = i;
			return (1);
		}
		i++;
	}
	return (0);
}

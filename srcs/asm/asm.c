/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:09 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/10 10:59:42 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	error(char *error)
{
	ft_putendl_fd(error, 2);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1])
		return (error("usage : ./asm [champion.s]"));
}

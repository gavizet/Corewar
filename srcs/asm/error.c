/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:23:09 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 17:27:18 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	line_error(char *error, int line)
{
	if (errno != 0)
		perror(error);
	else
		ft_printf("%s %d\n", error, line);
	exit(EXIT_FAILURE);
}

void	error(char *error)
{
	if (errno != 0)
		perror(error);
	else
		ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

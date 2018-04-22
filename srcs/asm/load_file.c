/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:08:25 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/22 19:47:28 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		load_file(t_asm *file)
{
	//int	fd;

	if (get_bytecode_data(file))
		return (1);
	/*
	if (!(fd = open(file->name, O_CREATE, O_WRONLY, 0644)))
			return (1);
	if (load_magic(file))
		return (1);
	if (load_header(file))
		return (1);
	if (load_body(file))
		return (1);
	*/
	return (0);
}

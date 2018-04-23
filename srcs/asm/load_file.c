/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:08:25 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 23:12:52 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	switch_endianness(unsigned int bytes)
{
	return ((bytes >> 24) + (((bytes << 8) >> 24) << 8) +
			(((bytes << 16) >> 24) << 16) + (bytes << 24));
}

int				get_prog_size(t_asm *file)
{
	t_list	*size;
	int		prog_size;

	prog_size = 0;
	size = file->lines;
	while (size)
	{
		prog_size += ((t_line*)(size->content))->len_to_load;
		if (prog_size > CHAMP_MAX_SIZE)
			return (0);
		size = size->next;
	}
	return (prog_size);
}

int				load_file(t_asm *file)
{
	int		fd;
	t_list	*lines;

	if (get_to_load_data(file))
		return (1);
	if ((file->header.prog_size = get_prog_size(file)) == 0)
		error("Error : champion prog size is too big");
	if ((fd = open(file->exec_name, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		error("Error : didn't manage to open .cor file");
	lines = file->lines;
	file->header.prog_size = switch_endianness(file->header.prog_size);
	file->header.magic = switch_endianness(file->header.magic);
	write(fd, &file->header, sizeof(t_header));
	while (lines)
	{
		if (((t_line*)(lines->content))->type == LINE_TYPE_INSTRU)
			write(fd, ((t_line*)(lines->content))->to_load,
					((t_line*)(lines->content))->len_to_load);
		lines = lines->next;
	}
	return (0);
}

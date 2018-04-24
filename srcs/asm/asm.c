/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:09 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 13:26:00 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_exe(t_asm *file, char *file_name)
{
	char	*search;
	char	*output;

	search = ft_strnew(0);
	output = ft_strnew(0);
	file->exec_name = ft_strnew(0);
	search = ft_strrchr(file_name, '.');
	if (!search)
		return (1);
	if (ft_strcmp(search, ".s"))
		return (1);
	output = ft_strnew(search - file_name + 4);
	ft_strncpy(output, file_name, search - file_name + 1);
	ft_strncpy(ft_strrchr(output, '.') + 1, "cor", 3);
	file->exec_name = output;
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	t_asm	file;

	if (ac != 2)
		error("usage : ./asm [champion.s]");
	init_file(&file);
	if (get_exe(&file, av[1]))
		error("Error : can't read source file");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("Error : failed to open source file");
	if (stock_file(&file, fd))
		error("Error : stock_file failed");
	if (parse_file(&file))
		error("Error : parse_file failed");
	if (load_file(&file))
		error("Error : load_file failed");
	ft_printf("Writing output program to %s\n", file.exec_name);
	return (0);
}

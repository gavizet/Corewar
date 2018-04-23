/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:09 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 21:42:27 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_exe(t_asm *file, char *file_name)
{
	char	*search;
	char	*final;

	search = ft_strrchr(file_name, '.');
	if (!search)
		return (1);
	if (ft_strcmp(search, ".s"))
		error("Erreur, format c monfi chier point S batar\n");
	final = ft_strsub(file_name, 0, ft_strlen(file_name) - ft_strlen(search));
	file->exec_name = ft_strcat(final, ".cor");
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
		error("Can't read source file");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("Failed to open source file");
	if (stock_file(&file, fd))
		error("Stock_file failed");
	if (parse_file(&file))
		error("Parse_file failed");
	if (load_file(&file))
		error("Load_file failed");
	ft_printf("Writing output program to %s\n", file.exec_name);
	return (0);
}

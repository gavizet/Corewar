/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:09 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 20:13:02 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_exe(t_asm *file, char *file_name)
{
	int 	len;
	char	*str;

	len = ft_strlen(file_name);
	if (file_name[len - 2] == '.' && file_name[len - 1] == 's')
	{
		if ((str = ft_strrchr(file_name, '/')))
			str = ft_strsub(str, 1, ft_strlen(str) - 3);
		else
			str = ft_strsub(file_name, 0, len - 2);
		file->exec_name = ft_strcat(str, ".cor");
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		fd;
	t_asm	file;

	if (ac != 2)
		error("usage : ./asm [champion.s]");
	init_file(&file);
	if (!get_exe(&file, av[1]))
		error("Can't read source file");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("Failed to open source file");
	if (!stock_file(&file, fd))
		error("Stock_file failed");
	if (!parse_file(&file))
		error("Parse_file failed");
	/*if (file->exec_name != NULL)
		load_file(&file);
	free_all();
	*/
	return (0);
}

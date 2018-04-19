/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:44:45 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/19 16:04:31 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_file(t_asm *file)
{
	ft_bzero(file->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(file->header.comment, COMMENT_LENGTH + 1);
	file->header.magic = COREWAR_EXEC_MAGIC;
	file->header.prog_size = 0;
	file->line_nb = 0;
	file->exec_name = NULL;
	file->lines = NULL;
}

int		init_line(t_asm *file, int line_type, char *str, int line_nb)
{
	t_line *line;

	if (!str || !(str))
		return (1);
	if (!(line = (t_line*)malloc(sizeof(t_line))))
		return (-1);
	line->str = ft_strtrim(str);
	line->tokens = NULL;
	line->type = line_type;
	line->line_nb = line_nb;
	line->got_label = 0;
	line->nb_arg = 0;
	line->nb_token = 0;
	line->to_load = ft_strnew(0);
	line->len_to_load = 0;
	//ft_printf("line[%d] | type = [%d] | [%s]\n", line->line_nb, line->type, line->str);
	if (*(line->str) && line->str)
		ft_lstaddback(&(file->lines), ft_lstnew((void*)line, sizeof(t_line)));
	free(line);
	return (1);
}
/*
int		init_token(t_line *line)
{

}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 13:44:45 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 16:25:48 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_file(t_asm *file)
{
	file->header.magic = COREWAR_EXEC_MAGIC;
	file->header.prog_size = 0;
	ft_bzero(file->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(file->header.comment, COMMENT_LENGTH + 1);
	file->lines = NULL;
	file->line_nb = 0;
	file->exec_name = NULL;
}

int		init_line(t_asm *file, int line_type, char *str, int line_nb)
{
	t_line *line;

	if (!str || !*str)
		return (0);
	if (!(line = (t_line*)malloc(sizeof(t_line))))
		error("malloc failed");
	line->tokens = NULL;
	line->line_nb = line_nb;
	line->len_to_load = 0;
	line->str = ft_strtrim(str);
	line->nb_arg = 0;
	line->type = line_type;
	line->got_label = 0;
	line->nb_token = 0;
	ft_bzero(line->to_load, 11);
	line->op = 0;
	//ft_printf("line[%d] | type = [%d] | [%s]\n", line->line_nb, line->type, line->str);
	if (line->str && *(line->str))
		ft_lstaddback(&(file->lines), ft_lstnew((void*)line, sizeof(t_line)));
	free(line);
	return (1);
}

int		init_token(t_line *line, int start, int end)
{
	t_token *token;

	if (!(token = (t_token*)malloc(sizeof(t_token))))
		return (-1);
	if (!(token->str = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (-1);
	token->value = 0;
	token->type = DONT_KNOW;
	ft_strncpy(token->str, &(line->str[start]), end - start);
	token->str[end - start] = 0;
	if (parse_token(token, line))
	{
		free(token);
		return (1);
	}
	//ft_printf(" |%s|", token->str);
	ft_lstaddback(&(line->tokens), ft_lstnew((void*)token, sizeof(t_token)));
	free(token);
	return (0);
}

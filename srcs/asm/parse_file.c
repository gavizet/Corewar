/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:58:41 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 19:40:49 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parse_prog_name(t_asm *file, t_line *name)
{
	int		i;
	int		end;

	i = 5;
	if ((ft_strncmp(name->str, NAME_CMD_STRING, 5)) != 0)
		return (1);
	while (is_empty_char((name->str)[i]))
		i++;
	if ((name->str)[i++] != '"')
		return (1);
	end = i;
	while (name->str && name->str[end] && (name->str)[end] != '"')
		end++;
	if (((name->str)[end] != '"') || end - i > PROG_NAME_LENGTH ||
			(name->str)[end + 1])
		return (1);
	ft_strncpy(file->header.prog_name, name->str + i, end - i);
	name->type = LINE_TYPE_NAME;
	file->header.magic = COREWAR_EXEC_MAGIC;
	return (0);
}

int		parse_comment(t_asm *file, t_line *comment)
{
	int		i;
	int		end;

	i = 8;
	if ((ft_strncmp(comment->str, COMMENT_CMD_STRING, 8)) != 0)
		return (1);
	while (is_empty_char((comment->str)[i]))
		i++;
	if ((comment->str)[i++] != '"')
		return (1);
	end = i;
	while (comment->str && comment->str[end] && (comment->str)[end] != '"')
		end++;
	if (((comment->str)[end] != '"') || end - i > COMMENT_LENGTH ||
			(comment->str)[end + 1])
		return (1);
	ft_strncpy(file->header.comment, comment->str + i, end - i);
	comment->type = LINE_TYPE_COMMENT;
	return (0);
}

int		parse_instru(t_line *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line->nb_token < MAX_TOKEN)
	{
		if (line->nb_token == 6)
			return (1);
		while (line->str[i] && is_empty_char(line->str[i]))
			i++;
		len = i;
		while (line->str[len] && !is_empty_char((line->str)[len]) &&
				(line->str)[len] != ',')
			len++;
		if (init_token(line, i, len))
			return (1);
		i = len + 1;
		if (!line->str[i - 1])
			return (0);
		line->nb_token++;
	}
	return (0);
}

int		parse_file_instru(t_line *line)
{
	if (parse_instru(line) || valid_params(line) || get_len_to_load(line))
	{
		line_error("Error at line", line->line_nb);
		return (1);
	}
	return (0);
}

int		parse_file(t_asm *file)
{
	int		parse;
	t_list	*lines;

	parse = 0;
	lines = file->lines;
	while (lines)
	{
		if (!(file->header.comment[0]) && parse == 1)
		{
			if (parse_comment(file, (t_line *)(lines->content)))
				error("Error during parse_comment");
			parse = 2;
		}
		if (!(file->header.prog_name[0]) && parse == 0)
		{
			if (parse_prog_name(file, (t_line *)(lines->content)))
				error("Error during parse_prog_name");
			parse = 1;
		}
		if (((t_line *)(lines->content))->type == LINE_TYPE_INSTRU)
			if (parse_file_instru((t_line*)lines->content))
				return (1);
		lines = lines->next;
	}
	return (0);
}

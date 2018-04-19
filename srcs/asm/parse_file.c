/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:58:41 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/19 17:55:23 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parse_prog_name(t_asm *file, t_line *name)
{
	int		i;
	int		end;

	i = 5;
	if ((ft_strncmp(name->str, NAME_CMD_STRING, 5)) != 0)
		return (0);
	while (is_empty_char((name->str)[i]))
		i++;
	if ((name->str)[i++] != '"')
		return (0);
	end = i;
	while ((name->str)[end] != '"')
		end++;
	if (((name->str)[end] != '"') || end - i > PROG_NAME_LENGTH ||
			(name->str)[end + 1])
		return (0);
	ft_strncpy(file->header.prog_name, name->str + i, end - i);
	name->type = LINE_TYPE_NAME;
	file->header.magic = COREWAR_EXEC_MAGIC;
	//ft_printf("file->header.prog_name == [%s]\n", file->header.prog_name);
	//ft_printf("file->header.magic == [%d]\n", file->header.magic);
	return (1);
}	

int		parse_comment(t_asm *file, t_line *comment)
{
	int		i;
	int		end;

	i = 8;
	if ((ft_strncmp(comment->str, COMMENT_CMD_STRING, 8)) != 0)
		return (0);
	while (is_empty_char((comment->str)[i]))
		i++;
	if ((comment->str)[i++] != '"')
		return (0);
	end = i;
	while ((comment->str)[end] != '"')
		end++;
	if (((comment->str)[end] != '"') || end - i > COMMENT_LENGTH ||
			(comment->str)[end + 1])
		return (0);
	ft_strncpy(file->header.comment, comment->str + i, end - i);
	comment->type = LINE_TYPE_COMMENT;
	//ft_printf("file->header.comment == [%s]\n", file->header.comment);
	return (1);
}	

int		is_valid_instr(char *instr)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((ft_strcmp(instr, OP_TAB(i).name)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		stock_token(t_line *line, char *tok)
{
	t_token *token;

	if (!(token = (t_token*)malloc(sizeof(t_token))))
		return (-1);
	token->value = 0;
	token->type = DONT_KNOW;
	token->str = ft_strdup(tok);
	ft_lstaddback(&(line->tokens), ft_lstnew((void*)token, sizeof(t_token)));
	return (1);
}

int		parse_instru(/*t_asm *file, */t_line *line)
{
	int		i;
	int		len;
	char	*token;

	i = 0;
	len = 0;
	while (line->nb_token < MAX_TOKEN)
	{
		while (is_empty_char((line->str)[i]))
			i++;
		len = i;
		while (!is_empty_char((line->str)[len]) && (line->str)[len] != ',')
			len++;
		token = ft_strsub(line->str, i, len - i);
		if (!stock_token(line, token, line->nb_token))
			error("TOKEN ERROR");
		ft_printf("token == [%s]\n", token);
		line->nb_token++;
	}
	return (1);
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
			if (!parse_comment(file, (t_line *)(lines->content)))
				return (0);
			parse = 2;
		}
		if (!(file->header.prog_name[0]) && parse == 0)
		{
			if (!parse_prog_name(file, (t_line *)(lines->content)))
				return (0);
			parse = 1;
		}
		if (((t_line *)(lines->content))->type == LINE_TYPE_INSTRU)
		{
			if (!parse_instru((t_line *)(lines->content)))
				return (0);
		}
		//ft_printf("line[%d] | type[%d] | [%s]\n", ((t_line *)(lines->content))->line_nb, ((t_line *)(lines->content))->type, ((t_line *)(lines->content))->str);
		lines = lines->next;
	}
	return (1);
}

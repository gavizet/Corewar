/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:58:41 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 20:13:00 by gavizet          ###   ########.fr       */
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
	//ft_printf(".name valide\n");
	//ft_printf("prog length == [%d]\n", end - i);
	//ft_printf("file->header.prog_name == [%s]\n", file->header.prog_name);
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
	//ft_printf(".comment valide\n");
	//ft_printf("comment length == [%d]\n", end - i);
	//ft_printf("file->header.comment == [%s]\n", file->header.comment);
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
		if (!file->header.prog_name[0] && parse < 1)
		{
			if (!parse_prog_name(file, (t_line *)(lines->content)))
				return (0);
			lines = lines->next;
			parse++;
		}
		if (!file->header.comment[0] && parse == 1)
		{
			if (!parse_comment(file, (t_line *)(lines->content)))
				return (0);
			lines = lines->next;
			parse++;
		}
		//if (((t_line *)(tmp->content))->type == LINE_TYPE_INSTRU)
		//	;
		//if (((t_line *)(tmp->content))->ype == LINE_TYPE_LABEL)
		//	;
		lines = lines->next;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:49:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 23:12:41 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label(t_asm *file, t_list *lines_list,
					t_line *lab_line, t_line *rule_line)
{
	int		value;
	t_list	*list;

	value = 0;
	if (lab_line->line_nb > rule_line->line_nb)
	{
		while (lines_list && (t_line*)(lines_list->content) != rule_line)
			lines_list = lines_list->next;
		while (lines_list && (t_line *)(lines_list->content) != lab_line)
		{
			value -= ((t_line*)(lines_list->content))->len_to_load;
			lines_list = lines_list->next;
		}
	}
	else if (lab_line->line_nb < rule_line->line_nb)
	{
		list = file->lines;
		while (list && (t_line *)(list->content) != lab_line)
			list = list->next;
		while (list && (t_line *)(list->content) != rule_line)
		{
			value += ((t_line*)(list->content))->len_to_load;
			list = list->next;
		}
	}
	return (value);
}

int		check_label(t_asm *file, t_list *line_list,
					t_line *lab_line, t_token *token)
{
	t_list	*lines;
	char	*label;

	lines = line_list;
	label = (token->type == LABEL) ? token->str + 2 : token->str + 1;
	while (lines)
	{
		if (((t_line*)(lines->content))->type == LINE_TYPE_LABEL)
		{
			if (!(ft_strcmp(((t_line *)(lines->content))->str, label)))
			{
				token->value = get_label(file, lines, lab_line,
											(t_line*)lines->content);
				return (0);
			}
		}
		lines = lines->next;
	}
	line_error("No corresponding label at line", lab_line->line_nb);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytecode_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/22 20:54:06 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label(t_list *lines_list, t_line *lab_line, t_line *rule_line)
{
	int		value;

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
	else
	{
		while (lines_list && (t_line *)(lines_list->content) != lab_line)
			lines_list = lines_list->next;
		while (lines_list && (t_line*)(lines_list->content) != rule_line)
		{
			value += ((t_line*)(lines_list->content))->len_to_load;
			lines_list = lines_list->next;
		}

	}
	return (value);
}

int		check_label(t_list *line_list, t_line *lab_line, t_token *token)
{
	t_list	*lines;
	char	*label;

	lines = line_list;
	label = (token->type == LABEL) ? token->str + 2 : token->str + 1;
	while (lines)
	{
		if (((t_line*)(lines->content))->type == LINE_TYPE_LABEL)
		{
			if (!ft_strcmp(((t_line *)(lines->content))->str, label))
			{
				token->value = get_label(lines, lab_line, (t_line*)lines->content);
				return (0);
			}
			else
				return (1);
		}
		lines = lines->next;
	}
	return (0);
}

int		get_number(t_list *line_list, t_line *lab_line, t_token *token)
{
	if (token->type == DIRECT)
		token->value = ft_atoi(++(token->str));
	if (token->type == REGISTER)
	{
		token->value = ft_atoi(++(token->str));
		if (token->value < 1 || token->value > 16)
			return (1);
	}
	if (token->type == INDIRECT)
		token->value = ft_atoi(token->str);
	if (token->type == LABEL || token->type == ADR_LABEL)
	{
		if (check_label(line_list, lab_line, token))
			return (1);
	}
	return (0);
}

int		get_params(t_asm *file, t_line *line)
{
	t_list *tokens;

	tokens = line->tokens->next;
	while (tokens)
	{
		if (get_number(file->lines, line, (t_token*)tokens->content))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

void	get_ocp(t_line *line)
{
	t_list	*tokens;
	int		ocp;
	int		bite;

	bite = 0;
	ocp = 0;
	tokens = line->tokens;
	if (!tokens->next)
		return ;
	tokens = tokens->next;
	while (tokens)
	{
		if (((t_token*)(tokens->content))->type == REGISTER)
			ocp |= 1 << (6 - bite);
		if (((t_token*)(tokens->content))->type == DIRECT ||
				((t_token*)(tokens->content))->type == LABEL)
			ocp |= 2 << (6 - bite);
		if (((t_token*)(tokens->content))->type == INDIRECT ||
				((t_token*)(tokens->content))->type == ADR_LABEL)
			ocp |= 3 << (6 - bite);
		bite += 2;
		tokens = tokens->next;
	}
	line->to_load[1] = ocp;
	ft_printf(" [%d ", line->to_load[0]);
	ft_printf("| %d]\n", line->to_load[1]);
}

int		get_bytecode_data(t_asm *file)
{
	t_list	*code;

	code = file->lines;
	while (code)
	{
	//	if (!(((t_line *)(code->content))->tokens->next))
	//		return (1);
		if (((t_line*)(code->content))->type == LINE_TYPE_INSTRU)
		{
			((t_line*)(code->content))->to_load[0] = ((t_line*)(code->content))->op;
			if (g_op_tab[((t_line*)(code->content))->op].ocp)
			{
				ft_printf("Instruction [%s] a un OCP ->", g_op_tab[((t_line*)(code->content))->op].name);
				get_ocp(((t_line*)(code->content)));
			}
			else
				ft_printf("Instruction [%s] n'a pas d'OCP\n", g_op_tab[((t_line*)(code->content))->op].name);
			if (get_params(file, (t_line *)(code->content)))
				return (1);
		}
		code = code->next;
	}
	return (0);
}

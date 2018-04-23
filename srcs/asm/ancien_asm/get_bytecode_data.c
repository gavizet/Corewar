/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytecode_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 21:24:03 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_number(t_asm *file, t_list *line_list, t_line *lab_line, t_token *token)
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
		if (check_label(file, line_list, lab_line, token))
			return (1);
	}
	return (0);
}

int		get_params(t_asm *file, t_line *line)
{
	t_list *tokens;
	size_t	octet;
	
	octet = 0;
	tokens = line->tokens->next;
	while (tokens)
	{
		if (get_number(file, file->lines, line, (t_token*)tokens->content))
			return (1);
		if (stock_token_in_to_load(line, (t_token*)tokens->content, &octet))
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
}

int		get_to_load_data(t_asm *file)
{
	t_list	*code;

	code = file->lines;
	while (code)
	{
		if (((t_line*)(code->content))->type == LINE_TYPE_INSTRU)
		{
			((t_line*)(code->content))->to_load[0] = ((t_line*)(code->content))->op + 1;
			if (g_op_tab[((t_line*)(code->content))->op].ocp)
			{
				get_ocp(((t_line*)(code->content)));
			}
			if (get_params(file, (t_line *)(code->content)))
				return (1);
		}
		code = code->next;
	}
	return (0);
}

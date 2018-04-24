/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:50:54 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 19:40:00 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		valid_params(t_line *line)
{
	int		ac;
	int		bin_arg;
	t_list	*tokens;

	ac = 0;
	tokens = line->tokens;
	if ((line->nb_token != g_op_tab[line->op].ac) || !tokens->next)
		return (1);
	tokens = tokens->next;
	while (tokens || ac < g_op_tab[line->op].ac)
	{
		if (((t_token *)(tokens->content))->type == LABEL)
			bin_arg = 2;
		else
			bin_arg = ((t_token *)(tokens->content))->type - 5;
		if (bin_arg == 11)
			bin_arg = 4;
		if (bin_arg & ~(g_op_tab[line->op].av[ac]))
			return (1);
		ac += 1;
		tokens = tokens->next;
	}
	return (0);
}

int		parse_token2(t_token *token)
{
	if (token->str[0] == DIRECT_CHAR)
	{
		token->type = (token->str[1] == LABEL_CHAR) ? LABEL : DIRECT;
		if (token->type == LABEL)
		{
			if (is_label(token->str, 2))
				return (1);
		}
		else if (token->type == DIRECT)
		{
			if (token->str[1] == '-')
			{
				if ((str_isdigit(token->str + 2)) == -1)
					return (1);
			}
			else if ((str_isdigit(token->str + 1)) == -1)
				return (1);
		}
	}
	else if ((str_isdigit(token->str)) == 1)
		token->type = INDIRECT;
	else
		return (1);
	return (0);
}

int		parse_token(t_token *token, t_line *line)
{
	if (is_valid_instr(token->str, line) && line->nb_token == 0)
		token->type = INSTRUCTION;
	else if (token->str[0] == REGISTER_CHAR)
	{
		token->type = REGISTER;
		if (is_reg(token))
			return (-1);
	}
	else if (token->str[0] == LABEL_CHAR)
	{
		token->type = ADR_LABEL;
		if (is_label(token->str, 1))
		{
			return (1);
		}
	}
	else if (parse_token2(token))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_token_in_load.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:53:40 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 21:33:24 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	stock_token_value(t_token *token, t_line *line, size_t *octet, int size)
{
	int	start;

	start = 1 + g_op_tab[line->op].ocp + *octet;
	if (size == 1)
		line->to_load[start] = token->value;
	if (size == 2)
	{
		line->to_load[start + 1] = token->value;
		line->to_load[start + 0] = (token->value >> 8);
	}
	if (size == 4)
	{
		line->to_load[start + 3] = token->value;
		line->to_load[start + 2] = (token->value >> 8);
		line->to_load[start + 1] = (token->value >> 16);
		line->to_load[start + 0] = (token->value >> 24);
	}
}

int		stock_token_in_to_load(t_line *line, t_token *token, size_t *octet)
{
	int	param_size;

	param_size = 0;
	if (token->type == REGISTER)
		param_size = 1;
	else if (token->type == DIRECT && g_op_tab[line->op].label_size)
		param_size = 2;
	else if (token->type == INDIRECT || token->type == ADR_LABEL)
		param_size = 2;
	else if (token->type == LABEL || (token->type == DIRECT &&
				g_op_tab[line->op].label_size))
		param_size = 2;
	else if (token->type == DIRECT)
		param_size = 4;
	stock_token_value(token, line, octet, param_size);
	*octet += param_size;
	return (0);
}

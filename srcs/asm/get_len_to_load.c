/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_to_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:57:15 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 21:28:21 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define OP_TAB_L	g_op_tab[line->op].label_size

int		get_len_to_load(t_line *line)
{
	t_list *tokens;

	tokens = line->tokens;
	if (!tokens)
		return (1);
	if (line->type == LINE_TYPE_INSTRU)
		line->len_to_load += 1;
	if (g_op_tab[line->op].ocp)
		line->len_to_load += 1;
	while (tokens)
	{
		if (((t_token*)(tokens->content))->type == REGISTER)
			line->len_to_load += 1;
		else if (((t_token*)(tokens->content))->type == DIRECT && !(OP_TAB_L))
			line->len_to_load += 4;
		else if (((t_token*)(tokens->content))->type == DIRECT && OP_TAB_L)
			line->len_to_load += 2;
		else if (((t_token*)(tokens->content))->type == INDIRECT ||
				((t_token*)(tokens->content))->type == ADR_LABEL)
			line->len_to_load += 2;
		else if (((t_token*)(tokens->content))->type == LABEL && OP_TAB_L)
			line->len_to_load += 2;
		tokens = tokens->next;
	}
	return (0);
}

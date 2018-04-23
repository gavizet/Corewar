/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytecode_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:31:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 17:04:22 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
# define GOT_OCP g_op_tab[line->op].ocp

int		get_label(t_asm *file, t_list *lines_list, t_line *lab_line, t_line *rule_line)
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
		//ft_printf("ligne actuelle [%d] == [%s]\n", ((t_line *)(list->content))->line_nb, ((t_line *)(list->content))->str);
		//ft_printf("lab_line [%d] == [%s]\n", lab_line->line_nb, lab_line->str);
		//ft_printf("rule_line [%d] == [%s]\n", rule_line->line_nb, rule_line->str);
		while (list && (t_line *)(list->content) != lab_line)
			list = list->next;
		//ft_printf("ligne actuelle 2 [%d] == [%s]\n", ((t_line *)(list->content))->line_nb, ((t_line *)(list->content))->str);
		while (list && (t_line *)(list->content) != rule_line)
		{
		//	ft_printf("len_to_load == [%d]\n", ((t_line*)list->content)->len_to_load);
			value += ((t_line*)(list->content))->len_to_load;
			list = list->next;
		}

	}
	//ft_printf("decalage entre les labels == [%d]\n", value);
	return (value);
}

int		check_label(t_asm *file, t_list *line_list, t_line *lab_line, t_token *token)
{
	t_list	*lines;
	char	*label;

	lines = line_list;
	label = (token->type == LABEL) ? token->str + 2 : token->str + 1;
	//ft_printf("Voici le label que je vais recherher dans le fichier | [%s]\n", label);
	while (lines)
	{
		if (((t_line*)(lines->content))->type == LINE_TYPE_LABEL)
		{
			if (!(ft_strcmp(((t_line *)(lines->content))->str, label)))
			{
				//ft_printf("J'ai trouve une rule correspondante | [%s]\n", ((t_line*)(lines->content))->str);
				token->value = get_label(file, lines, lab_line, (t_line*)lines->content);
				//ft_printf("Et sa valeur correspondante | [%d]\n", token->value);
				return (0);
			}
		}
		lines = lines->next;
	}
	//ft_printf("Je n'ai pas trouve de rule correspondante | ERROR\n");
	return (1);
}

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

void	stock_token_value(t_token *token, t_line *line, size_t *octet, int size)
{
	int	start;

	start = 1 + GOT_OCP + *octet;
	if (size == 1)
	{
		line->to_load[start] = token->value;
		//ft_printf("%d|", line->to_load[start]);
	}
	if (size == 2)
	{
		line->to_load[start + 1] = token->value;
		line->to_load[start + 0] = (token->value >> 8);
		//ft_printf("%d|", line->to_load[start]);
		//ft_printf("%d|", line->to_load[start + 1]);
	}
	if (size == 4)
	{
		line->to_load[start + 3] = token->value;
		line->to_load[start + 2] = (token->value >> 8);
		line->to_load[start + 1] = (token->value >> 16);
		line->to_load[start + 0] = (token->value >> 24);
		//ft_printf("%d|", line->to_load[start]);
		//ft_printf("%d|", line->to_load[start + 1]);
		//ft_printf("%d|", line->to_load[start + 2]);
		//ft_printf("%d|", line->to_load[start + 3]);
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
	else if (token->type == LABEL || (token->type == DIRECT && g_op_tab[line->op].label_size))
		param_size = 2;
	else if (token->type == DIRECT)
		param_size = 4;
	stock_token_value(token, line, octet, param_size);
	*octet += param_size;
	return (0);
}

int		get_params(t_asm *file, t_line *line)
{
	t_list *tokens;
	size_t	octet;
	
	octet = 0;
	tokens = line->tokens->next;
	//ft_printf("Voici la valeur des tokens que je recupere | ");
	//ft_printf("Args to load ==");
	//ft_printf(" |%d|", line->to_load[0]);
	//ft_printf("|%d|  ", line->to_load[1]);
	while (tokens)
	{
		if (get_number(file, file->lines, line, (t_token*)tokens->content))
			return (1);
		if (stock_token_in_to_load(line, (t_token*)tokens->content, &octet))
			return (1);
		//ft_printf("[%d] | ", ((t_token*)(tokens->content))->value);
		tokens = tokens->next;
	}
	//ft_printf("Line to Load == |%s|", line->to_load);
	//ft_printf("line [%d] | [%s]\n", line->line_nb, line->str);
	//ft_printf("to load == |");
	/*int	i = 0;
	while (i < line->len_to_load)
	{
		ft_printf(" %d |", line->to_load[i]);
		i++;
	}
	
	ft_printf("\n");*/
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
	//ft_printf(" [%d ", line->to_load[0]);
	//ft_printf("| %d]\n", line->to_load[1]);
}

int		get_bytelen(t_line *line)
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
		//ft_printf("token->type == [%d]\n", ((t_token*)(tokens->content))->type);
		if (((t_token*)(tokens->content))->type == REGISTER)
			line->len_to_load += 1;
		else if (((t_token*)(tokens->content))->type == DIRECT && !(g_op_tab[line->op].label_size))
			line->len_to_load += 4;
		else if (((t_token*)(tokens->content))->type == DIRECT && g_op_tab[line->op].label_size)
			line->len_to_load += 2;
		else if (((t_token*)(tokens->content))->type == INDIRECT ||
				((t_token*)(tokens->content))->type == ADR_LABEL  )
			line->len_to_load += 2;
		else if (((t_token*)(tokens->content))->type == LABEL && g_op_tab[line->op].label_size)
			line->len_to_load += 2;
		tokens = tokens->next;
	}
	return (0);
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
			//if (get_bytelen((t_line*)code->content))
			//	return (1);
			//ft_printf("len_to_load == [%d]\n", ((t_line*)(code->content))->len_to_load);
			((t_line*)(code->content))->to_load[0] = ((t_line*)(code->content))->op + 1;
			if (g_op_tab[((t_line*)(code->content))->op].ocp)
			{
				//ft_printf("Instruction [%s] a un OCP ->", g_op_tab[((t_line*)(code->content))->op].name);
				get_ocp(((t_line*)(code->content)));
			}
			//else
				//ft_printf("Instruction [%s] n'a pas d'OCP\n", g_op_tab[((t_line*)(code->content))->op].name);
			//ft_printf("La longeur de cette ligne est | [%d] octets\n", ((t_line*)(code->content))->len_to_load);
			if (get_params(file, (t_line *)(code->content)))
				return (1);
		}
		code = code->next;
	}
	return (0);
}

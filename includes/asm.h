/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:07 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/10 10:59:50 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "corewar.h"

typedef struct		s_asm
{
	t_list		*instr;
	char		*label; // A VOIR PLUS TARD
	int		opcode; // A VOIR PLUS TARD
	int		nb_arg;
	int		arg[3];
	int		arg_type[3];
}			t_asm;

#endif

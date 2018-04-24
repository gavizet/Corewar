/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:22:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:51:12 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	Soustrait le second parametre au premier parametre et stock le resultat
**	dans le troisieme parametre. Si le resultat est egal a zero, alors le carry
**	passe a 1, sinon a 0. Prend 10 cycles  s'executer.
*/

void	ft_sub(t_vm *data, t_proc *process)
{
	if (is_reg(process, 0) && is_reg(process, 1) && is_reg(process, 2))
	{
		if (verbose_operations(data))
			ft_printf("P %4d | sub r%d r%d r%d\n",
					ID, PARAM(0), PARAM(1), PARAM(2));
		REG(2) = REG(0) - REG(1);
		process->carry = REG(2) ? 0 : 1;
	}
	advance_pc(data, process);
}

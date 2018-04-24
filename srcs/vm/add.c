/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:44:48 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:19:56 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	Ajoute le second parametre au premier parametre. Stock l'addition des deux
**	dans le troisieme parametre. Si le resultat est egal a zero, alors le carry
**	passe a 1, sinon a 0. Prend 10 cycles  s'executer.
*/

void	ft_add(t_vm *data, t_proc *process)
{
	if (is_reg(process, 0) && is_reg(process, 1) && is_reg(process, 2))
	{
		if (verbose_operations(data))
			ft_printf("P %4d | add r%d r%d r%d\n", ID,
			MEMORY(PC + 2), MEMORY(PC + 3), MEMORY(PC + 4));
		REG(2) = REG(0) + REG(1);
		process->carry = (REG(2)) ? 0 : 1;
	}
	advance_pc(data, process);
}

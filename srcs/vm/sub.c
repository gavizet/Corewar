/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:22:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/03 13:25:17 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
	Soustrait le second parametre au premier parametre et stock le resultat
	dans le troisieme parametre. Si le resultat est egal a zero, alors le carry
	passe a 1, sinon a 0. Prend 10 cycles  s'executer.
*/

void	sub(t_vm *vm, t_process *process)
{
		if (is_reg(process, 0) && is_reg(process, 1) && is_reg(process, 2))
		{
			if (verbose_operations(vm))
				print_operations(process);
			REG(2) = REG(0) - REG(1);
			process->carry = (REG(2)) ? 0 : 1;
		}
		advance_pc(vm, process);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 09:19:49 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 14:55:15 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
/*
void	zjmp(t_vm *vm, t_process *process)
{
	int data;

	if (verbose_operations(vm))
		ft_printf("P %4d | zjmp %hd %s\n", ID, PARAM(0), (process->carry == 1) ? "OK" : "FAILED");
	data = PARAM(0) %= IDX_MOD;
	if (process->carry == 0)
		advance_pc(vm, process);
	process->pc2 = (process->carry == 1) ? (short)(process->pc + data) % MEM_SIZE : (process->pc + 3) % MEM_SIZE;
}
*/

void	zjmp(t_vm *vm, t_process *process)
{
	if (verbose_operations(vm))
		ft_printf("P %4d | zjmp %hd", ID, (short)PARAM(0));
	if (process->carry == 1)
	{
		if (verbose_operations(vm))
			ft_printf(" OK\n");
		process->pc2 = process->pc + ((short)process->param[0] % IDX_MOD);
		process->pc2 %= MEM_SIZE;
	}
	else
	{
		process->pc2 = (process->pc + 3) % MEM_SIZE;
		if (verbose_operations(vm))
			ft_printf(" FAILED\n");
		advance_pc(vm, process);
	}
}

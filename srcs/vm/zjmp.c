/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 09:19:49 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:54:52 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_zjmp(t_vm *data, t_proc *process)
{
	if (verbose_operations(data))
		ft_printf("P %4d | zjmp %hd", ID, (short)PARAM(0));
	if (process->carry == 1)
	{
		if (verbose_operations(data))
			ft_printf(" OK\n");
		process->reader = process->pc + ((short)process->av[0] % IDX_MOD);
		process->reader %= MEM_SIZE;
	}
	else
	{
		process->reader = (process->pc + 3) % MEM_SIZE;
		if (verbose_operations(data))
			ft_printf(" FAILED\n");
		advance_pc(data, process);
	}
}

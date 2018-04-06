/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:26:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 12:08:20 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		circular_mem(int adress)
{
	if (adress < 0)
		return ((adress % MEM_SIZE) + MEM_SIZE);
	else
		return (adress % MEM_SIZE);
}

void	print_adv(t_vm *vm, int actual_pc, int shift)
{
	int	i;

	i = 0;
	while (i++ < shift)
	{
		ft_printf("%.2x ", vm->memory[actual_pc % MEM_SIZE]);
		actual_pc = circular_mem(actual_pc + 1);
	}
}

int		calc_adv(t_process *process)
{
	int	i;
	int shift;

	shift = 1;
	i = OP_TAB.nb_param;
	if (OP_TAB.ocp)
	{
		while (--i >= 0)
		{
			if (process->param_type[i] == REG_CODE)
				shift += 1;
			else if (process->param_type[i] == IND_CODE || OP_TAB.label_size)
				shift += 2;
			else
				shift += 4;
		}
		shift += 1;
	}
	else if (!OP_TAB.ocp && OP_TAB.label_size)
		shift += 2;
	else
		shift += 4;
	return (shift);
}

int		advance_pc(t_vm *vm, t_process *process)
{
	int	shift;
	int	actual_pc;
	int	next_pc;

	actual_pc = process->pc;
	shift = calc_adv(process);
	next_pc = circular_mem(actual_pc + shift);
	process->pc = next_pc;
	if (verbose_pc(vm))
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", shift, actual_pc,
				actual_pc + shift);
		print_adv(vm, actual_pc, shift);
		ft_printf("\n");
	}
	return (next_pc);
}

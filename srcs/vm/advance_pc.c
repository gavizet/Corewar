/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:26:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/21 15:37:55 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		circular_mem(int adress)
{
	if (adress < 0)
		return ((adress % MEM_SIZE) + MEM_SIZE);
	else
		return (adress % MEM_SIZE);
}

void	print_adv(t_vm *data, int actual_pc, int shift)
{
	int	i;

	i = 0;
	actual_pc = circular_mem(actual_pc);
	while (i++ < shift)
	{
		ft_printf("%.2x ", data->ram[actual_pc % MEM_SIZE]);
		actual_pc = circular_mem(actual_pc + 1);
	}
}

int		calc_adv(t_proc *process)
{
	int	i;
	int shift;

	shift = 1;
	i = OP_TAB.ac;
	if (OP_TAB.ocp)
	{
		while (--i >= 0)
		{
			if (process->arg_type[i] == REG_CODE)
				shift += 1;
			else if (process->arg_type[i] == IND_CODE || OP_TAB.label_size)
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

int		advance_pc(t_vm *data, t_proc *process)
{
	int	shift;
	int	actual_pc;
	int	next_pc;

	actual_pc = circular_mem(process->pc);
	shift = calc_adv(process);
	shift = circular_mem(shift);
	next_pc = circular_mem(actual_pc + shift);
	process->pc = next_pc;
	if (verbose_pc(data))
	{
		ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", shift, actual_pc,
				actual_pc + shift);
		print_adv(data, actual_pc, shift);
		ft_printf("\n");
	}
	return (next_pc);
}

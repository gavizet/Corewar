/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:26:16 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/03 13:20:43 by gavizet          ###   ########.fr       */
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

void	print_operations(t_process *process)
{
	int	i;

	i = -1;
	ft_printf("P %4d | %s", process->id + 1, OP_TAB.name);
	while (++i < OP_TAB.nb_param)
	{
		ft_putchar(' ');
		if (process->param_type[i] == REG_CODE)
			ft_printf("r"); // cast en char, et printf avec %hhd
		else if (process->param_type[i] == IND_CODE || OP_TAB.label_size)
			ft_printf("IND"); // cast en short, et printf avec %hd
		else if (process->param_type[i] == DIR_CODE && !OP_TAB.label_size)
			ft_printf("%d", (int)PARAM(i));
	}
	ft_printf("\n");
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

	i = 0;
	shift = 1;
	while (i++ < OP_TAB.nb_param)
	{
		if (process->param_type[i] == REG_CODE)
			shift += 1;
		else if (process->param_type[i] == IND_CODE)
			shift += 2;
		else if (process->param_type[i] == DIR_CODE)
		{
			if (OP_TAB.label_size)
				shift += 2;
			else
				shift += 4;
		}
	}
	return(shift);
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
		ft_printf("ADV %d (%.4p -> %.4p) ", shift, actual_pc,
				actual_pc + shift);
		print_adv(vm, actual_pc, shift);
		ft_printf("\n");
	}
	return (next_pc);
}

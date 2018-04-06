/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:09:44 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 11:04:01 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(t_vm *vm, t_process *process)
{
	int	value[2];
	int	data;

	if (is_reg(process, 0))
	{
		value[0] = get_param(1, vm, process);
		value[1] = get_param(2, vm, process);
		if (value[0] && value[1])
		{
			data = circular_mem(PC + ((value[0] + value[1]) % IDX_MOD));
			store_reg(vm, data, REG(0));
			process->carry = REG(0) ? 0 : 1 ;
			if (verbose_operations(vm))
			{
				ft_printf("P %4d | sti r%hhd %d %d\n", ID, PARAM(0), value[0], value[1]);
				ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
					value[0], value[1], value[0] + value[1], PC + (value[0] + value[1]) % IDX_MOD);
			}
		}
	}
	advance_pc(vm, process);
}

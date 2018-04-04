/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:03:55 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 17:09:42 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	lldi(t_vm *vm, t_process *process)
{
	int	value[2];
	int	adress_to_load;

	if (is_reg(process, 2))
	{
		value[0] = get_param(0, vm, process);
		value[1] = get_param(1, vm, process);
		if (value[0] != -1 && value[1] != -1)
		{
			adress_to_load = circular_mem(PC + (value[0] + value[1]));
			REG(2) = ft_load(vm, 4, adress_to_load);
			process->carry = REG(2) ? 0 : 1;
			if (verbose_operations(vm))
			{
				ft_printf("P %4d | lldi %d %d r%d\n", ID, value[0], value[1], PARAM(2));
				ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
					value[0], value[1], value[0] + value[1], adress_to_load);
			}
		}
	}
	advance_pc(vm, process);
}

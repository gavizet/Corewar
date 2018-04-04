/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:18:27 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 15:38:21 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	xor(t_vm *vm, t_process *process)
{
	int param_value[2];

	if (is_reg(process, 2))
	{
		param_value[0] = get_param(0, vm, process);
		param_value[1] = get_param(1, vm, process);
		REG(2) = param_value[0] ^ param_value[1];
		process->carry = REG(2) ? 0 : 1;
		if (verbose_operations(vm))
			ft_printf("P% 5d | xor %d %d r%d\n", ID, param_value[0], param_value[1],
				PARAM(2));
	}
	advance_pc(vm, process);
}

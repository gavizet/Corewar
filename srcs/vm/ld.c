/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:25:42 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 12:07:03 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*

*/

void	ld(t_vm *vm, t_process *process)
{
	int	data;

	if (is_reg(process, 1))
	{
		if (PARAM_TYPE(0) == DIR_CODE)
			REG(1) = PARAM(0);
		else if (PARAM_TYPE(0) == IND_CODE)
		{
			data = circular_mem(PC + (PARAM(0) % IDX_MOD));
			REG(1) = ft_load(vm, 4, data);
		}
		if (verbose_operations(vm))
			ft_printf("P %4d | ld %d r%d\n", ID, REG(1), PARAM(1));
		process->carry = REG(1) ? 0 : 1;
	}
	advance_pc(vm, process);
}

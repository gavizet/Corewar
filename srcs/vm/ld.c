/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:25:42 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/03 14:19:18 by gavizet          ###   ########.fr       */
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
		if (verbose_operations(vm))
			print_operations(process);
		if (PARAM_TYPE(0) == DIR_CODE)
			REG(1) = PARAM(0);
		else if (PARAM_TYPE(0) == IND_CODE)
		{
			data = circular_mem(process->pc + (PARAM(0) % IDX_MOD));
			REG(1) = ft_load(vm, 4, data);
		}
		process->carry = REG(1) ? 0 : 1;
	}
	advance_pc(vm, process);
}

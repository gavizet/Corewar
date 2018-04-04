/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:31:52 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 12:07:01 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	st(t_vm *vm, t_process *process)
{
	int	data;

	if (is_reg(process, 0))
	{
		if (PARAM_TYPE(1) == REG_CODE && is_reg(process, 1))
		{
			REG(1) = REG(0);
			if (verbose_operations(vm))
				ft_printf("P %4d | st r%d %d\n", ID, PARAM(0), PARAM(1));
		}
		else if (PARAM_TYPE(1) == IND_CODE)
		{
			data = circular_mem(PC + (PARAM(1) % IDX_MOD));
			ft_store(vm, process, data);
			if (verbose_operations(vm))
				ft_printf("P %4d | st r%d %d\n", ID, PARAM(0), PARAM(1));
		}
		process->carry = REG(0) ? 0 : 1 ;
	}
	advance_pc(vm, process);
}

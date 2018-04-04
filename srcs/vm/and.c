/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:04:54 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 14:15:37 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_param(int param_nb, t_vm *vm, t_process *process)
{
	int	param_value;

	if (PARAM_TYPE(param_nb) == REG_CODE && is_reg(process, param_nb))
		param_value = REG(param_nb);
	else if (PARAM_TYPE(param_nb) == DIR_CODE)
		param_value = PARAM(param_nb);
	else if (PARAM_TYPE(param_nb) == IND_CODE)
		param_value = ft_load(vm, 4, PC + (PARAM(param_nb) % IDX_MOD));
	else
		return (0);
	return (param_value);
}

void	and(t_vm *vm, t_process *process)
{
	int param_value[2];

	if (is_reg(process, 2))
	{
		param_value[0] = get_param(0, vm, process);
		param_value[1] = get_param(1, vm, process);
		REG(2) = param_value[0] & param_value[1];
		process->carry = REG(2) ? 0 : 1;
		if (verbose_operations(vm))
			ft_printf("P% 5d | and %d %d r%d\n", ID, param_value[0], param_value[1],
				PARAM(2));
	}
	advance_pc(vm, process);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:23:28 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/02 14:23:29 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static int	get_param_value(t_process *process, int param, int *val, t_vm *vm)
{
	if (process->param_type[param] == T_REG)
	{
		if (process->param[param] >= 1 && process->param[param] <= 16)
			*val = process->reg[process->param[param] - 1];
		else
			return (0);
	}
	else if (process->param_type[param] == T_DIR)
		*val = process->param[param];
	else
		*val = ft_load(vm, 4, process->pc + process->param[param] % IDX_MOD);
	return (1);
}

void		ft_and(t_vm *vm, t_process *process)
{
	int		val1;
	int		val2;

	if (process->param[2] >= 1 && process->param[2] <= 16)
	{
		if (!get_param_value(process, 0, &val1, vm) ||
			!get_param_value(process, 1, &val2, vm))
		{
			ft_adv_invalid(process, vm);
			return ;
		}
		ft_verbose(vm, process);
		process->reg[process->param[2] - 1] = val1 & val2;
		process->carry = !process->reg[process->param[2] - 1];
		ft_verbose2(process, vm);
	}
	else
		ft_adv_invalid(process, vm);
}

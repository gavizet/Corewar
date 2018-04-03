/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuclin <gbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:31:36 by gbuclin           #+#    #+#             */
/*   Updated: 2018/04/03 10:06:10 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	ft_add(t_vm *vm, t_process *process)
{
	if (process->param[0] >= 1 && process->param[0] <= 16
		&& process->param[1] >= 1 && process->param[1] <= 16
		&& process->param[2] >= 1 && process->param[2] <= 16)
	{
		ft_verbose(vm, process);
		process->reg[process->param[2] - 1] =
			process->reg[process->param[0] - 1] +
			process->reg[process->param[1] - 1];
		process->carry = !process->reg[process->param[2] - 1];
		ft_verbose2(process, vm);
	}
	else
		ft_adv_invalid(process, vm);
}

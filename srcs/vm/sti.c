/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:09:44 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:50:01 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_verbose_sti(t_proc *process, int *value, int address)
{
	ft_printf("P %4d | sti r%d %d %d\n",
			ID, (short)PARAM(0), value[0], value[1]);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			value[0], value[1], value[0] + value[1], address);
}

void	ft_sti(t_vm *data, t_proc *process)
{
	int	value[2];
	int	address;

	if (is_reg(process, 0))
	{
		value[0] = get_param(1, data, process);
		value[1] = get_param(2, data, process);
		if (value[1] == ERR_CODE_PARAM || value[0] == ERR_CODE_PARAM)
		{
			advance_pc(data, process);
			return ;
		}
		address = (PC + ((value[0] + value[1]) % IDX_MOD));
		store_reg(data, circular_mem(address), REG(0));
		if (verbose_operations(data))
		{
			ft_verbose_sti(process, value, address);
		}
	}
	advance_pc(data, process);
}

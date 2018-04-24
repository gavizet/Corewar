/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:25:07 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:55:42 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		ft_verbose_ldi(t_proc *process, int *value)
{
	ft_printf("P %4d | ldi %d %d r%d\n", ID, value[0], value[1], PARAM(2));
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
	value[0], value[1], value[0] + value[1],
	PC + (value[0] + value[1]) % IDX_MOD);
}

void			ft_ldi(t_vm *data, t_proc *process)
{
	int	value[2];
	int	adress_to_load;

	if (is_reg(process, 2))
	{
		value[0] = get_param(0, data, process);
		value[1] = get_param(1, data, process);
		if (value[0] != ERR_CODE_PARAM && value[1] != ERR_CODE_PARAM)
		{
			adress_to_load = circular_mem(PC + ((value[0] + value[1])
						% IDX_MOD));
			REG(2) = ft_ramcpy(data, 4, adress_to_load);
			process->carry = REG(2) ? 0 : 1;
			if (verbose_operations(data))
			{
				ft_verbose_ldi(process, value);
			}
		}
	}
	advance_pc(data, process);
}

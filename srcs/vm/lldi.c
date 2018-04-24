/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:03:55 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:58:37 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		ft_verbose_lldi(t_proc *process, int *value,
		int address_to_load)
{
	ft_printf("P %4d | lldi %d %d r%d\n", ID, value[0], value[1], PARAM(2));
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			value[0], value[1], value[0] + value[1], address_to_load);
}

void			ft_lldi(t_vm *data, t_proc *process)
{
	int	value[2];
	int	address_to_load;

	if (is_reg(process, 2))
	{
		value[0] = get_param(0, data, process);
		value[1] = get_param(1, data, process);
		if (value[0] != ERR_CODE_PARAM && value[1] != ERR_CODE_PARAM)
		{
			address_to_load = circular_mem(PC + (value[0] + value[1]));
			REG(2) = ft_ramcpy(data, 4, address_to_load);
			process->carry = REG(2) ? 0 : 1;
			if (verbose_operations(data))
			{
				ft_verbose_lldi(process, value, address_to_load);
			}
		}
	}
	advance_pc(data, process);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:51:56 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 18:54:58 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_lld(t_vm *data, t_proc *process)
{
	int	address;

	if (is_reg(process, 1))
	{
		if (PARAM_TYPE(0) == DIR_CODE)
			REG(1) = PARAM(0);
		else if (PARAM_TYPE(0) == IND_CODE)
		{
			address = circular_mem(PC + PARAM(0));
			REG(1) = ft_ramcpy(data, 4, address);
		}
		if (verbose_operations(data))
			ft_printf("P %4d | lld %d r%d\n", ID, REG(1), PARAM(1));
		process->carry = REG(1) ? 0 : 1;
	}
	advance_pc(data, process);
}

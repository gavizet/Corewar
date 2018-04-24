/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:31:52 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:42:23 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	ft_st(t_vm *data, t_proc *process)
{
	int	i;

	if (is_reg(process, 0))
	{
		if (PARAM_TYPE(1) == REG_CODE)
		{
			if (!is_reg(process, 1))
			{
				advance_pc(data, process);
				return ;
			}
			REG(1) = REG(0);
			if (verbose_operations(data))
				ft_printf("P %4d | st r%d %d\n", ID, PARAM(0), PARAM(1));
		}
		else if (PARAM_TYPE(1) == IND_CODE)
		{
			i = circular_mem(PC + (PARAM(1) % IDX_MOD));
			store_reg(data, i, REG(0));
			if (verbose_operations(data))
				ft_printf("P %4d | st r%d %d\n", ID, PARAM(0), PARAM(1));
		}
	}
	advance_pc(data, process);
}

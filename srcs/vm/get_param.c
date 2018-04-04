/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:15:45 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 15:16:01 by gavizet          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:15:45 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 22:58:37 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int		get_param_long(t_vm *data, t_proc *process, int param, int *val)
{
	if (PARAM_TYPE(param) == REG_CODE)
	{
		if (is_reg(process, param))
			*val = REG(param);
		else
			return (0);
	}
	else if (process->arg_type[param] == DIR_CODE)
		*val = PARAM(param);
	else
		*val = ft_ramcpy(data, 4, (process->pc + process->av[param]));
	return (1);
}

int		get_param(int param_nb, t_vm *data, t_proc *process)
{
	int	param_value;

	if (PARAM_TYPE(param_nb) == REG_CODE && is_reg(process, param_nb))
		param_value = REG(param_nb);
	else if (PARAM_TYPE(param_nb) == DIR_CODE)
		param_value = PARAM(param_nb);
	else if (PARAM_TYPE(param_nb) == IND_CODE)
		param_value = ft_ramcpy(data, 4, PC + PARAM(param_nb));
	else
		return (ERR_CODE_PARAM);
	return (param_value);
}

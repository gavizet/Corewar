/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:15:30 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 14:41:38 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		ft_arg_types(t_vm *data, t_proc *process)
{
	int i;
	int ret;
	int adv;

	process->reader = circular_mem(process->reader);
	process->ocp = data->ram[process->reader % MEM_SIZE];
	process->arg_type[0] = data->ram[process->reader % MEM_SIZE] >> 6;
	process->arg_type[1] = (data->ram[process->reader % MEM_SIZE] & 48) >> 4;
	process->arg_type[2] = (data->ram[process->reader % MEM_SIZE] & 12) >> 2;
	i = -1;
	adv = 2;
	ret = 0;
	while (++i < g_op_tab[(int)process->opcode].ac)
	{
		if (process->arg_type[i] == REG_CODE)
			adv++;
		else if (PARAM_TYPE(i) == DIR_CODE && (!(OP_TAB.label_size)))
			adv = adv + DIR_SIZE;
		else if (PARAM_TYPE(i) == IND_CODE || (PARAM_TYPE(i) == DIR_CODE &&
				(g_op_tab[(int)process->opcode].label_size)))
			adv = adv + IND_SIZE;
		if ((ft_types_check(process, i)))
			ret++;
	}
	return (ret ? adv : 0);
}

static void		ft_args_cpy(t_vm *data, t_proc *process)
{
	int	i;

	i = -1;
	while (++i < g_op_tab[(int)process->opcode].ac)
	{
		if (process->arg_type[i] == 2 &&
				g_op_tab[(int)process->opcode].label_size == 0)
		{
			process->av[i] = ft_ramcpy(data, 4, process->reader);
			process->reader = (process->reader + 4) % MEM_SIZE;
		}
		else if (process->arg_type[i] == 1)
		{
			process->av[i] = (unsigned char)ft_ramcpy(data, 1, process->reader);
			process->reader = (process->reader + 1) % MEM_SIZE;
		}
		else
		{
			process->av[i] = (short)ft_ramcpy(data, 2, process->reader);
			process->reader = (process->reader + 2) % MEM_SIZE;
		}
	}
}

static int		ft_get_args(t_vm *data, t_proc *process)
{
	int ret;

	process->reader = (process->pc + 1) % MEM_SIZE;
	if (g_op_tab[(int)process->opcode].ocp)
	{
		if ((ret = ft_arg_types(data, process)))
			return (ret);
	}
	else
	{
		ret = LAB_SIZE;
		process->av[0] = ft_ramcpy(data,
				ret, process->reader);
		process->reader = (process->reader + ret) % MEM_SIZE;
		return (0);
	}
	process->reader = (process->reader + 1) % MEM_SIZE;
	ft_args_cpy(data, process);
	return (0);
}

static void		ft_parse_instruction(t_vm *data, t_proc *process)
{
	if (data->ram[(process->pc + MEM_SIZE) % MEM_SIZE] >= 1 &&
			data->ram[(process->pc + MEM_SIZE) % MEM_SIZE] <= 16)
	{
		process->opcode = data->ram[(process->pc + MEM_SIZE) % MEM_SIZE] - 1;
		process->at_cycle = g_op_tab[(int)process->opcode].cycles - 1;
	}
	else
		process->reader = ++(process->pc) % MEM_SIZE;
}

void			ft_process(t_vm *data, t_proc *process)
{
	int ret;

	if (--process->at_cycle == 0)
	{
		if ((ret = ft_get_args(data, process)))
		{
			if (data->verbose)
				hexdump_adv(data, process, ret);
			process->pc = (process->pc + ret) % MEM_SIZE;
		}
		else
		{
			data->f[(int)process->opcode](data, process);
			process->pc = process->reader % MEM_SIZE;
		}
		process->opcode = -1;
	}
	else if (process->opcode == -1)
		ft_parse_instruction(data, process);
}

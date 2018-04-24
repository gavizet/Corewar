/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 14:52:00 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"
#include <stdio.h>

int				ft_types_check(t_proc *process, int i)
{
	if (process->arg_type[i] == REG_CODE)
		return (g_op_tab[(int)process->opcode].av[i] & T_REG ? 0 : 1);
	else if (process->arg_type[i] == IND_CODE)
		return (g_op_tab[(int)process->opcode].av[i] & T_IND ? 0 : 1);
	else if (process->arg_type[i] == DIR_CODE)
		return (g_op_tab[(int)process->opcode].av[i] & T_DIR ? 0 : 1);
	else if (!(process->arg_type[i]))
		return (1);
	return (0);
}

void			hexdump_adv(t_vm *data, t_proc *process, int adv)
{
	int	i;

	adv = circular_mem(adv);
	process->pc = circular_mem(process->pc);
	ft_printf("ADV %d (0x%.4x -> 0x%.4x) %.2x %.2x ", adv, process->pc,
			process->pc + adv, data->ram[(process->pc) % MEM_SIZE],
			data->ram[(process->pc + 1) % MEM_SIZE]);
	i = 1;
	while (++i < adv)
		ft_printf("%.2x ", data->ram[(process->pc + i) % MEM_SIZE]);
	ft_printf("\n");
}

void			ft_dump_data(t_vm *data)
{
	int	reader;
	int offset;

	reader = -1;
	offset = 0;
	while (++reader < MEM_SIZE)
	{
		if (reader % 64 == 0)
		{
			offset == 0 ? ft_printf("0x%#.4x : ", offset) :\
					ft_printf("\n%#.4x : ", offset);
			offset = offset + 64;
		}
		ft_printf("%.2x ", (unsigned char)data->ram[reader]);
	}
	ft_printf("\n");
}

int				ft_ramcpy(t_vm *data, int size, int pc)
{
	int	arg;

	arg = 0;
	while (pc < 0)
		pc += MEM_SIZE;
	if (size == 1)
		arg = data->ram[pc % MEM_SIZE];
	else if (size == 2)
	{
		arg = data->ram[(pc + 1) % MEM_SIZE];
		arg |= ((data->ram[pc % MEM_SIZE]) << 8);
	}
	else
	{
		arg = data->ram[(pc + 3) % MEM_SIZE];
		arg |= ((data->ram[(pc + 2) % MEM_SIZE]) << 8);
		arg |= ((data->ram[(pc + 1) % MEM_SIZE]) << 16);
		arg |= ((data->ram[pc % MEM_SIZE]) << 24);
	}
	return (arg);
}

unsigned int	switch_endianness(unsigned int bytes)
{
	return ((bytes >> 24) + (((bytes << 8) >> 24) << 8) +
			(((bytes << 16) >> 24) << 16) + (bytes << 24));
}

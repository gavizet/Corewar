/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:19:23 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:22:38 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		copy_process(t_vm *data, t_proc *process, t_proc *copy)
{
	int	nb;

	nb = REG_NUMBER;
	while (nb--)
		copy->reg[nb] = process->reg[nb];
	copy->player = process->player;
	copy->pc = (process->pc + ((short)(process->av[0]) % IDX_MOD)) % MEM_SIZE;
	while (copy->pc < 0)
		copy->pc += MEM_SIZE;
	copy->num = data->nb_proc++;
	copy->header = process->header;
	copy->player = process->player;
	copy->id = data->nb_proc;
	copy->carry = process->carry;
	copy->at_cycle = 0;
	copy->live_at_cycle = process->live_at_cycle;
	ft_lstadd(&data->processes, ft_lstnew(copy, sizeof(t_proc)));
}

static void		copy_processlfork(t_vm *data, t_proc *process, t_proc *copy)
{
	int	nb;

	nb = REG_NUMBER;
	while (nb--)
		copy->reg[nb] = process->reg[nb];
	copy->player = process->player;
	copy->pc = (process->pc + ((short)(process->av[0]))) % MEM_SIZE;
	while (copy->pc < 0)
		copy->pc += MEM_SIZE;
	copy->num = data->nb_proc++;
	copy->header = process->header;
	copy->player = process->player;
	copy->id = data->nb_proc;
	copy->carry = process->carry;
	copy->at_cycle = 0;
	copy->live_at_cycle = process->live_at_cycle;
	ft_lstadd(&data->processes, ft_lstnew(copy, sizeof(t_proc)));
}

static t_proc	*create_new_process(void)
{
	int		par_nb;
	t_proc	*process;

	par_nb = -1;
	if (!(process = (t_proc*)malloc(sizeof(t_proc))))
		exit_error(ERR_MALLOC, NULL);
	while (++par_nb < 3)
	{
		PARAM(par_nb) = 0;
		PARAM_TYPE(par_nb) = 0;
	}
	process->at_cycle = 0;
	process->opcode = -1;
	return (process);
}

void			ft_fork(t_vm *data, t_proc *process)
{
	t_proc	*copy;

	copy = create_new_process();
	copy->pc = circular_mem(PC + (PARAM(0) % IDX_MOD));
	copy_process(data, process, copy);
	if (verbose_operations(data))
		ft_printf("P% 5d | fork %hd (%d)\n",
				ID, PARAM(0), PC + (short)PARAM(0) % IDX_MOD);
	advance_pc(data, process);
}

void			ft_lfork(t_vm *data, t_proc *process)
{
	t_proc	*copy;

	copy = create_new_process();
	copy->pc = circular_mem(PC + PARAM(0));
	copy_processlfork(data, process, copy);
	if (verbose_operations(data))
		ft_printf("P% 5d | lfork %hd (%d)\n",
				ID, PARAM(0), PC + (short)PARAM(0));
	advance_pc(data, process);
}

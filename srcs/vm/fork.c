/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:19:23 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/06 19:58:42 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		copy_process(t_vm *vm, t_process *process, t_process *copy)
{
	int	nb;

	nb = REG_NUMBER;
	while (nb--)
		copy->reg[nb] = process->reg[nb];
	copy->id_champ = process->id_champ;
	copy->pc = circular_mem(PC + PARAM(0));
	copy->id = vm->nb_process++;
	copy->header = process->header;
	copy->carry = process->carry;
	copy->cycles_wo_live = process->cycles_wo_live;
	copy->color = process->color;
	ft_lstadd(&vm->processes, ft_lstnew(copy, sizeof(t_process)));
}

static t_process	*create_new_process()
{
	int	par_nb;
	t_process *process;

	par_nb = -1;
	if (!(process = (t_process*)malloc(sizeof(t_process))))
		ft_exit_malloc_error();
	while (++par_nb < 3)
	{
		PARAM(par_nb) = 0;
		PARAM_TYPE(par_nb) = 0;
	}
	process->cycle_bf_exe = 0;
	process->instruction = -1;
	return (process);
}

void			my_fork(t_vm *vm, t_process *process)
{
	t_process	*copy;

	copy = create_new_process();
	copy->pc = circular_mem(PC + (PARAM(0) % IDX_MOD));
	copy_process(vm, process, copy);
	if (verbose_operations(vm))
		ft_printf("P% 5d | fork %hd (%d)\n", ID, PARAM(0), PC + (short)PARAM(0) % IDX_MOD);
	advance_pc(vm, process);
}

void			my_lfork(t_vm *vm, t_process *process)
{
	t_process	*copy;

	copy = create_new_process();
	copy->pc = circular_mem(PC + PARAM(0));
	copy_process(vm, process, copy);
	if (verbose_operations(vm))
		ft_printf("P% 5d | lfork %hd (%d)\n", ID, PARAM(0), PC + (short)PARAM(0));
	advance_pc(vm, process);
}

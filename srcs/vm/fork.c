/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:19:23 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/04 19:29:32 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void	ft_copy_reg(t_process *process, t_process *old_process)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		PARAM(i) = 0;
		PARAM_TYPE(i) = 0;
	}
	i = -1;
	while (++i < 16)
		process->reg[i] = old_process->reg[i];
}

static void	fork2(t_vm *vm, t_process *process, t_process *new_process,
	t_list *lst)
{
	new_process->carry = process->carry;
	new_process->cycle_bf_exe = 0;
	new_process->instruction = -1;
	new_process->cycles_wo_live = process->cycles_wo_live;
	new_process->color = process->color;
	ft_copy_reg(new_process, process);
	lst->content = new_process;
	lst->next = NULL;
	lst->content_size = sizeof(t_list);
	ft_lstadd(&vm->processes, lst);
	advance_pc(vm, process);
}

void		my_fork(t_vm *vm, t_process *process)
{
	t_list		*lst;
	t_process	*new_process;

	lst = NULL;
	if (((new_process = (t_process*)malloc(sizeof(t_process))) == NULL) ||
		((lst = (t_list *)malloc(sizeof(t_list))) == NULL))
		ft_exit_malloc_error();
	new_process->header = process->header;
	new_process->id = vm->nb_process++;
	new_process->id_champ = process->id_champ;
	new_process->pc = circular_mem(process->pc + (PARAM(0) % IDX_MOD));
	if (verbose_operations(vm))
		ft_printf("P% 5d | fork %hd (%hhd)\n", ID, PARAM(0), new_process->pc);
	fork2(vm, process, new_process, lst);
}

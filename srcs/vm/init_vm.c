/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:41:54 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/20 18:03:04 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static t_proc	*ft_mkproc(t_vm *data, int pnum)
{
	t_proc		*the_process;

	if (!(the_process = (t_proc*)malloc(sizeof(t_proc))))
		return (NULL);
	the_process->num = pnum;
	the_process->player = 0;
	the_process->live_at_cycle = 0;
	the_process->opcode = (char)-1;
	the_process->ocp = 0;
	the_process->reader = 0;
	the_process->header = NULL;
	the_process->pc = 0;
	the_process->id = data->nb_players - (data->nb_players - the_process->num);
	ft_bzero(&the_process->reg[0], (REG_SIZE * REG_NUMBER));
	ft_bzero(&the_process->av[0], sizeof(int) * 3);
	ft_bzero(&the_process->arg_type[0], (sizeof(t_arg_type) * 3));
	the_process->reg[0] = -1 * (char)pnum;
	return (the_process);
}

t_list			*ft_add_process(t_vm *data, t_list *processes, int pnum)
{
	t_list	*new;
	t_proc	*process;

	if (!(process = ft_mkproc(data, pnum)))
		return (NULL);
	if (!(new = (t_list*)ft_lstnew((void*)process, (sizeof(t_proc)))))
		return (NULL);
	if (processes == NULL)
		return (new);
	else
		ft_lstadd(&processes, new);
	return (processes);
}

void			ft_init_vm(t_vm *data)
{
	int	i;

	i = -1;
	data->nb_players = 0;
	data->dump = -1;
	data->flags = NO_FLAG;
	data->verbose = 0;
	data->aff = 0;
	data->cycles = 1;
	data->players_alive = 0;
	data->cycle_reduction = 0;
	data->cycle_check = CYCLE_TO_DIE;
	data->processes = NULL;
	data->checks = 0;
	data->live = 0;
	data->last_live = 0;
	data->headers = NULL;
	ft_bzero((void*)data->ram, MEM_SIZE);
	ft_bzero((void*)data->pnums, sizeof(int) * (MAX_PLAYERS + 1));
	while (++i < 4)
		ft_bzero((void*)data->players[i], CHAMP_MAX_SIZE);
}

void			ft_init_instructions(t_vm *data)
{
	data->f[0] = ft_live;
	data->f[1] = ft_ld;
	data->f[2] = ft_st;
	data->f[3] = ft_add;
	data->f[4] = ft_sub;
	data->f[5] = ft_and;
	data->f[6] = ft_or;
	data->f[7] = ft_xor;
	data->f[8] = ft_zjmp;
	data->f[9] = ft_ldi;
	data->f[10] = ft_sti;
	data->f[11] = ft_fork;
	data->f[12] = ft_lld;
	data->f[13] = ft_lldi;
	data->f[14] = ft_lfork;
	data->f[15] = ft_aff;
}

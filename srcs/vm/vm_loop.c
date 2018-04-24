/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 19:25:27 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 14:53:41 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

t_header	*get_header(t_vm *data, t_list *headers, int player)
{
	int			i;
	int			j;
	t_header	*ret;

	i = -1;
	j = 0;
	while (++i < MAX_PLAYERS && i < player)
	{
		if (data->pnums[i])
			j++;
	}
	if (j == 0)
		j++;
	headers = ft_lst_at(headers, data->nb_players - j);
	ret = ((t_header*)(headers->content));
	return (ret);
}

void		ft_herald_winner(t_vm *data)
{
	t_list		*headers;
	t_header	*head;

	headers = data->headers;
	if (data->cycles < data->dump || data->dump < 0)
	{
		head = get_header(data, headers, ABS(data->last_live));
		ft_printf("Contestant %d, \"%s\", has won !\n",
				(ABS(data->last_live) ? ABS(data->last_live) : 1),
				head->prog_name);
	}
}

static void	ft_check_alive(t_vm *data)
{
	t_proc	*process;
	t_list	*cur;
	int		i;

	i = 0;
	cur = data->processes;
	while (cur)
	{
		i++;
		process = (t_proc*)cur->content;
		cur = cur->next;
		if (process->live_at_cycle >= CYCLE_TO_DIE -
				(CYCLE_DELTA * data->cycle_reduction))
		{
			if (data->verbose)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
						process->id, process->live_at_cycle, REDUCED_CTD(data));
			ft_lstrm_at(&(data->processes), i--);
		}
	}
}

static void	ft_cycles(t_vm *data)
{
	data->cycles++;
	if (data->cycles > data->cycle_check)
	{
		ft_check_alive(data);
		data->checks++;
		if (data->live > (NBR_LIVE - 1) || data->checks == MAX_CHECKS)
		{
			data->cycle_reduction++;
			data->cycle_check += CYCLE_TO_DIE -
				(CYCLE_DELTA * data->cycle_reduction);
			if (data->verbose)
				ft_printf("Cycle to die is now %d\n",
						REDUCED_CTD(data));
			data->checks = 0;
		}
		else
			data->cycle_check += REDUCED_CTD(data);
		data->live = 0;
	}
}

void		ft_vm_loop(t_vm *data, t_list *processes)
{
	t_proc	*process;

	while ((data->cycles <= data->dump || data->dump < 0) && processes)
	{
		if (data->verbose)
			ft_printf("It is now cycle %d\n", data->cycles);
		while (processes)
		{
			process = (t_proc*)processes->content;
			process->live_at_cycle++;
			ft_process(data, process);
			processes = processes->next;
		}
		ft_cycles(data);
		processes = data->processes;
	}
	if (processes)
		ft_dump_data(data);
}

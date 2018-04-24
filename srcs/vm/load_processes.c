/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:11:36 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 14:31:22 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			ft_herald(t_list *lstproc, t_vm *data)
{
	t_proc		*process;
	t_header	*head;
	int			i;
	int			j;

	i = -1;
	j = 0;
	ft_printf("Introducing contestants...\n");
	while (++i < MAX_PLAYERS)
	{
		if (data->pnums[i])
		{
			j++;
			process = (t_proc*)(ft_lst_at(lstproc,
						data->pnums[MAX_PLAYERS] - j))->content;
			head = process->header;
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
					process->player, head->prog_size, head->prog_name,
					head->comment);
		}
	}
}

static t_header	*ft_champ_header(t_vm *data, t_list *listheaders, int pnum)
{
	int			i;
	t_header	*header;

	i = MAX_PLAYERS;
	while (--i > pnum)
	{
		if (data->pnums[i])
		{
			if (listheaders)
				listheaders = listheaders->next;
			else
				exit_error("Error in headers distribution", NULL);
		}
	}
	if (listheaders)
		header = listheaders->content;
	else
		header = NULL;
	return (header);
}

void			ft_copy_champs(t_vm *data, t_list *listheaders)
{
	int			i;
	int			ram_index;
	t_header	*header;

	i = -1;
	ram_index = 0;
	while (++i < MAX_PLAYERS)
	{
		if (data->pnums[i] != 0)
		{
			if (listheaders == NULL)
				exit_error(ERR_UNKNOWN, NULL);
			header = ft_champ_header(data, listheaders, i);
			ft_memcpy(&data->ram[ram_index], data->players[i],
					(size_t)header->prog_size);
			ram_index = ((ram_index + (MEM_SIZE / data->nb_players))
					% MEM_SIZE);
		}
	}
	data->nb_proc = data->nb_players;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:32:26 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 16:38:08 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void	ft_parse_instructions(t_list *lst, char *player, int fd)
{
	int			r;
	int			psize;
	t_header	*header;

	header = (t_header*)lst->content;
	psize = (int)header->prog_size;
	if ((r = read(fd, player, psize)) == -1)
		exit_error(ERR_READ, NULL);
	if (r != psize)
		exit_error(ERR_SIZE, NULL);
	if (!((r = read(fd, player, 10)) == 0))
		exit_error(ERR_SIZE, NULL);
}

static void	ft_parse_headers(t_vm *data, int fd, int pnum)
{
	t_header	*header;
	t_list		*new;
	int			i;

	if (!(header = (t_header*)malloc(sizeof(t_header))))
		exit_error(ERR_MALLOC, NULL);
	if ((i = read(fd, (void *)(header), sizeof(t_header))) == -1)
		exit_error(ERR_READ, NULL);
	if (i != sizeof(t_header))
		exit_error(ERR_HEADER, NULL);
	header->magic = switch_endianness(header->magic);
	header->prog_size = switch_endianness(header->prog_size);
	if (header->prog_size > CHAMP_MAX_SIZE)
		exit_error("Champ too big in ", data->players[pnum]);
	if (!(new = ft_lstnew(((void*)header), sizeof(t_header))))
		exit_error(ERR_MALLOC, NULL);
	ft_lstadd(&(data->headers), new);
}

static int	ft_count_champs(t_vm *data)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (data->players[i][0])
		{
			if (data->pnums[i])
				(data->pnums[MAX_PLAYERS])++;
			else
				return (1);
		}
		else if (data->pnums[i])
			return (1);
	}
	if (data->pnums[MAX_PLAYERS] == (int)data->nb_players)
		return (0);
	return (1);
}

void		ft_parse_champs(t_vm *data)
{
	int	i;
	int fd;

	i = -1;
	if (ft_count_champs(data))
		exit_error("Error in champs parsing", NULL);
	while (++i < MAX_PLAYERS)
	{
		if (data->pnums[i])
		{
			if ((fd = open(data->players[i], O_RDONLY)) != -1)
			{
				ft_bzero(data->players[i], CHAMP_MAX_SIZE);
				ft_parse_headers(data, fd, i);
				ft_parse_instructions(data->headers, data->players[i], fd);
				if ((fd = close(fd)) == -1)
					exit_error(ERR_READ, NULL);
			}
			else
				exit_error(ERR_READ, NULL);
		}
	}
}

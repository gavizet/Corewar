/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:40:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/16 14:49:39 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_mkchamp(t_vm *data, char *arg)
{
	int i;
	int done;

	i = -1;
	done = 0;
	while (++i < MAX_PLAYERS && !done)
	{
		if (data->players[i][0] == 0)
		{
			ft_strcpy(data->players[i], arg);
			data->pnums[i] = 1;
			done = 1;
		}
	}
	if (!done)
	{
		exit_error("Too many champions", NULL);
		return (-1);
	}
	else
		return (0);
}

static int	ft_parse_dump(char *arg)
{
	int res;

	res = 0;
	if (arg)
		if (ft_isdigitstr(arg))
			if ((res = ft_atoi(arg)) >= 0)
				return (ft_atoi(arg));
	if (res < 0)
		exit_error(ERR_DUMP, NULL);
	else
		print_usage();
	return (-1);
}

static void	ft_parse_flags(char arg, t_vm *data)
{
	if (arg == 'a' && (!(FLAG_AFF & data->flags)))
		data->flags += FLAG_AFF;
	else if (arg == 'c' && (!(FLAG_CURSES & data->flags)))
		data->flags += FLAG_CURSES;
	else if (arg == 'g' && (!(FLAG_COLOR & data->flags)))
		data->flags += FLAG_COLOR;
	else
		print_usage();
}

static int	ft_parse_pnum(char **arg, t_vm *data, int i)
{
	int res;

	if (arg[i] && arg[i + 1])
	{
		if (ft_isdigitstr(arg[i]))
		{
			if (((res = ft_atoi(arg[i])) <= MAX_PLAYERS && res > 0))
			{
				ft_strcpy(data->players[res - 1], arg[i + 1]);
				data->pnums[res - 1] = 1;
				return (i + 1);
			}
			else
				exit_error(ERR_PNUM, NULL);
		}
		else
			exit_error(ERR_PNUM, NULL);
	}
	else
		print_usage();
	return (-1);
}

void		ft_parse_arguments(int argc, char **argv, t_vm *data)
{
	int	i;
	int	pnum;

	i = 0;
	pnum = 0;
	while (++i < argc && data->nb_players <= MAX_PLAYERS)
	{
		if (!(ft_strcmp(argv[i], "-dump")))
			data->dump = ft_parse_dump(argv[++i]);
		else if (!(ft_strcmp(argv[i], "-n")))
			i = ft_parse_pnum(argv, data, i + 1);
		else if (!(ft_strcmp(argv[i], "-v")))
			data->verbose = (unsigned char)(ft_parse_dump(argv[++i]));
		else if (ft_strlen(argv[i]) == 2 && argv[i][0] == '-')
			ft_parse_flags(argv[i][1], data);
		else if ((pnum = open(argv[i], O_RDONLY)) != -1)
		{
			pnum = close(pnum);
			ft_mkchamp(data, argv[i]);
		}
		else if (pnum == -1)
			exit_error(ERR_READ, argv[i]);
	}
}

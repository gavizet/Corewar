/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 17:27:42 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/21 17:55:06 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"
#include "../../includes/vm.h"
#include "../../libft/includes/libft.h"

static void	ft_the_function_at_the_end(t_vm *data)
{
	if (data->processes)
		ft_lstdel(&(data->processes), &ft_lstdelcontent);
	if (data->headers)
		ft_lstdel(&(data->headers), &ft_lstdelcontent);
}

int			main(int argc, char **argv)
{
	t_vm	data;

	if (argc > 1)
	{
		ft_init_vm(&data);
		ft_init_instructions(&data);
		ft_parse_arguments(argc, argv, &data);
		ft_check_data(&data);
		ft_parse_champs(&data);
		ft_create_processes(&data);
		ft_copy_champs(&data, data.headers);
		ft_herald(data.processes, &data);
		ft_vm_loop(&data, data.processes);
		ft_herald_winner(&data);
		ft_the_function_at_the_end(&data);
	}
}

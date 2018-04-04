/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 13:48:14 by lgosse            #+#    #+#             */
/*   Updated: 2018/04/04 13:04:50 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	ft_graphic_handle(t_vm *vm, int adress)
{
	int		idx;

	idx = 0;
	while (idx < 4)
	{
		if (vm->mem_color[adress + idx] >= 0)
			attron(COLOR_PAIR(vm->mem_color[(adress + idx) % MEM_SIZE]));
		else
			attron(COLOR_PAIR(5));
		mvwprintw(stdscr, ((adress + idx) % MEM_SIZE) / 64 + 2,
			((adress + idx) % MEM_SIZE) % 64 * 3 + 3, "%.2x ",
			vm->memory[(adress + idx) % MEM_SIZE]);
		if (vm->mem_color[(adress + idx) % MEM_SIZE] >= 0)
			attroff(COLOR_PAIR(vm->mem_color[(adress + idx) % MEM_SIZE]));
		else
			attroff(COLOR_PAIR(5));
		idx++;
	}
}

void	store_reg(t_vm *vm, int adress, int reg_val)
{
	MEMORY(adress + 3) = reg_val;
	MEMORY(adress + 2) = (reg_val >> 8);
	MEMORY(adress + 1) = (reg_val >> 16);
	MEMORY(adress + 0) = (reg_val >> 24);
}

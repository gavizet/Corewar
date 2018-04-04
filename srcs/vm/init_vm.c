/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbuclin <gbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:08:12 by gbuclin           #+#    #+#             */
/*   Updated: 2018/04/04 17:48:20 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void		ft_init_ncurses(t_vm *vm)
{
	setlocale(LC_ALL, "");
	initscr();
	start_color();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	init_pair(7, COLOR_WHITE, COLOR_RED);
	init_pair(8, COLOR_WHITE, COLOR_YELLOW);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	ft_init_visu(vm);
}

void		ft_init_vm(t_vm *vm)
{
	vm->dump = -1;
	vm->processes = NULL;
	vm->champions = NULL;
	vm->nb_champ = 0;
	vm->verbose = 0;
	vm->aff = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->total_cycles = 1;
	vm->cycles = 1;
	vm->live = 0;
	vm->last_live = 0;
	vm->ctd_decrem = 0;
	vm->aff = 0;
	vm->ncurses = 0;
	vm->nb_checks = 0;
	vm->sleep = 10000;
}

void		ft_init_process(t_process *process)
{
	process->id_champ = process->reg[0];
	process->nb_live = 0;
}

void		init_tab_instruction(t_vm *vm)
{
	//vm->f[0] = live;
	vm->f[1] = ld;
	vm->f[2] = st;
	vm->f[3] = add;
	vm->f[4] = sub;
	vm->f[5] = and;
	vm->f[6] = or;
	vm->f[7] = xor;
	//vm->f[8] = zjmp;
	vm->f[9] = ldi;
	vm->f[10] = sti;
	vm->f[11] = my_fork;
	vm->f[12] = lld;
	vm->f[13] = lldi;
	/*vm->f[14] = lfork;
	vm->f[15] = aff;*/
}

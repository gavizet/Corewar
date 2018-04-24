/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:55:05 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 16:41:51 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define LARED			(data->cycle_reduction)
# define REDUCED_CTD(data)	(CYCLE_TO_DIE - (CYCLE_DELTA * LARED))
# define LAB_SIZE		(g_op_tab[(int)process->opcode].label_size ? 2 : 4);
# define MEMORY(X)		data->ram[(unsigned int)(X) % MEM_SIZE]
# define ID				(process->id)
# define ID1			(process->num + 1)
# define PC				process->pc
# define REG(x)			process->reg[process->av[(x)] - 1]
# define PARAM(x)		process->av[(x)]
# define PARAM_TYPE(x)	process->arg_type[(x)]
# define OP_TAB			g_op_tab[(int)process->opcode]

# define ERR_READ		"Can't read source file "
# define ERR_MALLOC		"Couldn't allocate memory"
# define ERR_DUMP		"Dump and verbose values cannot be negative"
# define ERR_PNUM		"Invalid player number"
# define ERR_HEADER		"Invalid header "
# define ERR_SIZE		"Program size does not match header"
# define ERR_UNKNOWN	"Unknown error happened. Exiting"
# define ERR_CODE_PARAM	-2147483444
# define NO_FLAG		0
# define FLAG_AFF		1
# define FLAG_CURSES	2
# define FLAG_COLOR		4

typedef struct		s_proc
{
	int				reg[REG_NUMBER];
	char			player;
	char			num;
	int				id;
	int				av[3];
	t_arg_type		arg_type[3];
	char			opcode;
	int				pc;
	int				reader;
	int				at_cycle;
	int				live_at_cycle;
	int				duration;
	int				ocp;
	int				carry;
	int				live;
	int				color;
	t_header		*header;
}					t_proc;

typedef struct		s_vm
{
	unsigned char	ram[MEM_SIZE];
	unsigned char	nb_players;
	unsigned char	verbose;
	unsigned char	flags;
	t_list			*processes;
	char			players[MAX_PLAYERS][CHAMP_MAX_SIZE];
	int				pnums[MAX_PLAYERS + 1];
	t_list			*headers;
	int				cycles;
	int				nb_proc;
	int				players_alive;
	int				cycle_reduction;
	int				cycle_check;
	int				dump;
	int				checks;
	int				live;
	int				last_live;
	int				aff;
	void			(*f[16])(struct s_vm *, t_proc *);
}					t_vm;

void				ft_init_vm(t_vm *data);
t_list				*ft_add_process(t_vm *data, t_list *processes, int pnum);
void				ft_create_processes(t_vm *data);
void				ft_find_header_pnum(t_vm *data, int pnum);
void				ft_get_header_number(t_vm *data, int players,
		t_proc *processes, int i);
t_proc				*ft_get_proc_pnum(t_vm *data, int pnum);
void				ft_parse_arguments(int argc, char **argv, t_vm *data);
void				ft_parse_champs(t_vm *data);
void				ft_copy_champs(t_vm *data, t_list *listheaders);
int					ft_check_data(t_vm *data);
void				ft_herald(t_list *lstproc, t_vm *data);
void				ft_herald_winner(t_vm *data);
void				ft_vm_loop(t_vm *data, t_list *processes);
void				ft_process(t_vm *data, t_proc *process);
unsigned int		ft_check_endianness(t_vm *data);
int					ft_types_check(t_proc *process, int i);
unsigned int		switch_endianness(unsigned int bytes);
void				hexdump_adv(t_vm *data, t_proc *process, int adv);
int					ft_ramcpy(t_vm *data, int size, int pc);
void				exit_error(char *error, char *file);
void				print_usage(void);
void				ft_dump_data(t_vm *data);
void				ft_init_instructions(t_vm *data);
int					advance_pc(t_vm *data, t_proc *process);
int					verbose_operations(t_vm *data);
int					is_reg(t_proc *process, int nb_param);
int					get_param(int param_nb, t_vm *data, t_proc *process);
int					circular_mem(int address);
void				store_reg(t_vm *data, int address, int reg_val);
int					verbose_pc(t_vm *data);
int					verbose_live(t_vm *data);
int					get_param_long(t_vm *data, t_proc *process,
		int param, int *val);

void				ft_add(t_vm *data, t_proc *process);
void				ft_aff(t_vm *data, t_proc *process);
void				ft_and(t_vm *data, t_proc *process);
void				ft_fork(t_vm *data, t_proc *process);
void				ft_lfork(t_vm *data, t_proc *process);
void				ft_ld(t_vm *data, t_proc *process);
void				ft_ldi(t_vm *data, t_proc *process);
void				ft_live(t_vm *data, t_proc *process);
void				ft_lld(t_vm *data, t_proc *process);
void				ft_lldi(t_vm *data, t_proc *process);
void				ft_or(t_vm *data, t_proc *process);
void				ft_st(t_vm *data, t_proc *process);
void				ft_sti(t_vm *data, t_proc *process);
void				ft_sub(t_vm *data, t_proc *process);
void				ft_xor(t_vm *data, t_proc *process);
void				ft_zjmp(t_vm *data, t_proc *process);

void				ft_vomit_data(t_vm *data);
void				ft_print_headers(t_vm *data);
void				ft_something_something(t_vm *data);
void				ft_herald_debug(t_list *procs);

#endif

#include "vm.h"

char	*get_player(t_vm *vm, int nb_champ)
{
	t_list		*champs;
	t_process	*process;

	champs = vm->champions;
	while (champs)
	{
		process = champs->content;
		if (nb_champ == process->id_champ)
		{
			process->nb_live++;
			return (process->header.prog_name);
		}
		champs = champs->next;
	}
	return (NULL);
}

void	live(t_vm *vm, t_process *process)
{
	char	*player;

	process->cycles_wo_live = 0;
	vm->live += 1;
	if (verbose_operations(vm))
		ft_printf("P% 5d | live %d\n", ID, PARAM(0));
	player = get_player(vm, PARAM(0));
	if (player)
	{
		vm->last_live = PARAM(0);
		if (verbose_live(vm))
			ft_printf("Player %d (%s) is said to be alive\n", PARAM(0), player);
	}
	advance_pc(vm, process);
}

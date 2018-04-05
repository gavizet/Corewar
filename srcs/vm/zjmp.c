#include "vm.h"

void	zjmp(t_vm *vm, t_process *process)
{
	int data;

	if (verbose_operations(vm))
		ft_printf("P %4d | zjmp %hd %s\n", ID, PARAM(0), (process->carry == 1) ? "OK" : "FAILED");
	data = PARAM(0) %= IDX_MOD;
	if (process->carry == 0)
		advance_pc(vm, process);
	process->pc = (process->carry == 1) ? (short)(process->pc + data) % MEM_SIZE : (process->pc + 3) % MEM_SIZE;
}

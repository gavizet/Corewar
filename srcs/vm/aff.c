#include "vm.h"

void	aff(t_vm *vm, t_process *process)
{
	int	character;

	if (is_reg(process, 0) && vm->aff)
	{
		character = REG(0) % 256;
		ft_printf("Aff : %c\n", (char)character);
		process->carry = (!character) ? 1 : 0;
	}
	advance_pc(vm, process);
}

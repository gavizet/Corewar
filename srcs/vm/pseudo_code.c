/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:28:43 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/03 14:19:21 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_get_arg(param)
{
	int data;

	data = 0;
	if (param_type == REG et param > 1 et < 16)
		data = process->reg[param]
	else if (param == DIR)
		data = process[param[param]];
	else if (param == IND)
		data = get_adress_value(param); // ou load() ; partie de bob
	return (data);
}

void	live(vm, process)
{
	Incrementation du live, TMTC ma gueule.
	Remettre process->cycle_to_die q 0.
	if (param_type == DIR && (param1 >= 0 && param1 <= 4))
	{
		process->id_champ = param1 * -1;
		if (param1 = process->id_champ)
			process->nb_live += 1;
		vm->last_live = -param1;
		printf("Le joueur $player_name ($player_id) a ete rapporte comme etant en vie");
	}
	// A VOIR PLUS TARD EN FONCTION DE CE QUE FAIT BOB AU NIVEAU DES CHAMPS
}

void	ld(vm, process)
{
	int	get_value;

	if (check_arg(param1) && param_type2 == REG)
	{
		if (param1 == DIR)
			param2 = param1;
		else if (param2 == IND)
		{
			get_value = (pc + (param1 % IDX_MOD)) % MEM_SIZE;
			param2 = ft_load(process, vm, 4, get_value);
		}	
		param2 = value;
		carry = value ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	st(vm, process)
{
	int	stored;
	
	if (param_type1 == REG && check_arg(param2))
	{
		if (param_type2 == REG)
			param2 = param1;
		else if (param_type2 == IND)
		{
			stored = (pc + (param2 % IDX_MOD)) % MEM_SIZE;
			store_in_mem(vm, process, stored); // Operations chimique a faire avec decalages binaire
		}
		carry = param1 ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	add(vm, process)
{
	if (param_type1 == registre && param_type2 == registre et param_type3 == registre)
	{
		param3 = param1 + param2;
		if (param3)
			carry = 1;
		else
			carry = 0;
		print_verbose();
	}
	else
		invalid_params();
}

void	sub(vm, process)
{
	if (param_type1 == registre && param_type2 == registre et param_type3 == registre)
	{
		param3 = param1 - param2;
		if (param3)
			carry = 1;
		else
			carry = 0;
		print_verbose();
	}
	else
		invalid_params();

}

void	and(vm, process)
4{
	int	value[2];

	if (check_arg(param1) && check_arg(param2) && param3 == registre)
	{
		value[0] = get_arg(process, vm);
		value[1] = get_arg(process, vm);
		param3 = value[0] & value[1];
		carry = param3 ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	or(vm, process)
{
	int	value[2];

	if (check_arg(param1) && check_arg(param2) && param3 == registre)
	{
		value[0] = get_arg(process, vm);
		value[1] = get_arg(process, vm);
		param3 = value[0] | value[1];
		carry = param3 ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	xor(vm, process)
{
	int	value[2];

	if (check_arg(param1) && check_arg(param2) && param3 == registre)
	{
		value[0] = get_arg(process, vm);
		value[1] = get_arg(process, vm);
		param3 = value[0] ^ value[1];
		carry = param3 ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	zjmp(vm, process)
{
	if (carry == 1 && param_type1 == DIR)
	{
		pc = (pc + (param % IDX_MOD)) % MEM_SIZE
		print_verbose();
	}
	else
	{
		pc += 3;
		invalid_params();
	}


}

void	ldi(vm, process)
{
	int	value[2];
	int	total;

	if (check_arg(param1) && check_arg(param2) && param_type3 == REG)
	{
		value[0] = get_arg(process, vm);
		value[1] = get_arg(process, vm);
		total = (pc + ((value[0] + value[1]) % IDX_MOD)) % MEM_SIZE;
		param3 = ft_load(process, vm, 2, total);
		carry = total ? 0 : 1;
		printf_verbose();
	}
	else
		invalid_params();
}

void	sti(vm, process)
{
	int	value[2];
	int	stored;
	
	if (param_type1 == REG && check_arg(param2) && check_arg(param3))
	{
		value[0] = get_arg(process, vm, param2);
		value[1] = get_arg(process, vm, param3);
		stored = (pc + ((value[0] + value[1]) % IDX_MOD)) % MEM_SIZE;
		store_reg_in_mem(vm, process, stored); // Store la valeur du registre (param1) a l'adresse stored). LE FUN.
		}
		carry = param1 ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	fork(vm, process)
{
	t_process duplicate;

	if (param_type1 == DIR)
	{
		create_process(duplicate);
		// Faire une fonction de creation de processus ou en utiliser une deja
		// existante dans le parsing.
		copy_process(process, duplicate);
		// Appelle une fonction qui copie variable par variable le processus actuel.
		// A voir si ce n'est pas possible de le faire plus efficacement que
		// avec de l'assignation de valeur comme un bourrin.
		duplicate->pc = (process->pc + (param1 % IDX_MOD)) % MEM_SIZE;
	}
	else
		invalid_params();
}

void	lld(vm, process) // pareil que ld sans l'adressage restreint (IDX_MOD)
{
	int	get_value;

	if (check_arg(param1) && param_type2 == REG)
	{
		if (param1 == DIR)
			param2 = param1;
		else if (param2 == IND)
		{
			get_value = (pc + param1) % MEM_SIZE;
			param2 = ft_load(process, vm, 4, get_value);
		}	
		param2 = value;
		carry = value ? 0 : 1;
		print_verbose();
	}
	else
		invalid_params();
}

void	lldi(vm, process) // Pareil que ldi sans restriction de l'adressage.
{
	int	value[2];
	int	total;

	if (check_arg(param1) && check_arg(param2) && param_type3 == REG)
	{
		value[0] = get_arg(process, vm);
		value[1] = get_arg(process, vm);
		total = (pc + (value[0] + value[1])) % MEM_SIZE;
		param3 = ft_load(process, vm, 2, total);
		carry = total ? 0 : 1;
		printf_verbose();
	}
	else
}

void	lfork(vm, process)
{
	Voir fork. Pareil mais sans restriction de l'adressage (% IDX_MOD)
}

void	aff(vm, process)
{
	if (param_type1 == REG)
	{
		ft_printf("%c", (param1 % 256));
		carry = param1 ? 0 : 1;
	}
	else
		invalid_params();
}

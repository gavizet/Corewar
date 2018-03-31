/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:44:48 by gavizet           #+#    #+#             */
/*   Updated: 2018/03/31 17:34:57 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
	Ajoute le second parametre au premier parametre. Stock l'addition des deux
	dans le troisieme parametre. Si le resultat est egal a zero, alors le carry
	passe a 1, sinon a 0. Prend 10 cycles  s'executer.

Verifier que les trois parametre sont bien des registres.
Si c'est le cas, alors additionner la valeur des deux premier dans le troisieme
Analyser le resulat. Si > 0, le carry passe a 1. Sinon, il passe a 0.
*/

void	ft_add(t_vm *vm, t_process *process)
{
	(void)vm;
	(void)process;
/*	if (param1 == registre && param2 == registre && param3 == registre)
	{
		param3 = param1 + param2;
		if (param3 != 0)
			carry = 1;
		carry =0;
	}*/
}

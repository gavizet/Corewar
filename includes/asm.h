#ifndef ASM_H
# define ASM_H

typedef struct		s_asm
{
	t_list		*instr;
	char		*label; // A VOIR PLUS TARD
	int		opcode; // A VOIR PLUS TARD
	int		nb_arg;
	int		arg[3];
	int		arg_type[3]
}			t_asm

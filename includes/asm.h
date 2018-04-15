/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:07 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 19:21:47 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/includes/libft.h"

# define COMM_CHAR #
# define COMMA_CHAR ,
# define REGISTER_CHAR r
# define END_COMM_CHAR ;
# define LABEL_LEN 2

typedef enum		e_token_type
{
	LINE_TYPE_LABEL, // label
	LINE_TYPE_INSTRU, // instruction
	STRING, // wesh si tu comprends pas je te demonte
	REGISTER, // pareil
	DIRECT, // pareil++
	INDIRECT, // pareil++ numero 2
	ADR_LABEL // adresse de ton label
}					t_token_type;

typedef struct		s_asm
{
	int				line_nb; // Nombre de ligne dans le fichier
	char			*exec_name; // Nom de l'executable
	t_list			*lines; // Contient toutes les lignes du fichier
	t_header		header; // Contient tout notre header
}					t_asm;

typedef struct		s_token
{
	t_op 			*instr; // Tableau d'instrction dans op.c
	char			*str; // Chaine correspondant au token
	int				value; // Valeur du token;
	t_token_type	type; // Type du token
}					t_token;

typedef struct		s_line
{
	int				len_to_load; // Longueur de la ligne en bytecode
	t_list			*tokens; // Liste des tokens de cette ligne. Stock d'une structure token dans chaque maillon
	int				got_label; // Savoir si la ligne contient un label
	int				nb_arg; // Nombre d'arguments dans la ligne
	char			*str; // Ligne en entier une fois qu'elle a ete strstrim
	char			*to_load; // Ligne en entier
	int				line_nb;
	t_token_type	type; // Type de la ligne
}					t_line;

// utils.c

int		is_empty_char(int n);
int		line_is_empty(char *str);
int		line_is_comment(char *str);

// error.c

void	error(char *error);

// init_structs.c

void	init_file(t_asm *file);
int		init_line(t_asm *file, int line_type, char *str, int line_nb);

// stock_file.c

int		stock_file(t_asm *file, int fd);

// parse_file.c

int		parse_file(t_asm *file);

#endif

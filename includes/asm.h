/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:34:07 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/23 18:01:39 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"
# include "../libft/includes/libft.h"

extern t_op			g_op_tab[17];

# define MAX_TOKEN				7
# define COMM_CHAR				'#'
# define REGISTER_CHAR			'r'
# define END_COMM_CHAR			';'
# define LABEL_LEN				2
# define OP_TAB(x)				g_op_tab[(x)]

typedef enum		e_token_type
{
	DONT_KNOW = 0,
	LINE_TYPE_NAME,
	LINE_TYPE_COMMENT,
	LINE_TYPE_LABEL,
	LINE_TYPE_INSTRU,
	INSTRUCTION,
	REGISTER,
	DIRECT,
	INDIRECT = 9,
	LABEL,
	ADR_LABEL = 16
}					t_token_type;

typedef struct		s_asm
{
	int				line_nb;
	char			*exec_name;
	t_list			*lines;
	t_header		header;
}					t_asm;

typedef struct		s_token
{
	char			*str;
	int				value;
	t_token_type	type;
}					t_token;

typedef struct		s_line
{
	t_list			*tokens;
	char			*str;
	unsigned char	to_load[11];
	int				nb_arg;
	int				got_label;
	int				line_nb;
	int				nb_token;
	int				len_to_load;
	int				op;
	t_token_type	type;
}					t_line;

/*
** utils.c
*/

int					is_empty_char(int n);
int					is_reg(t_token *token);
int					line_is_empty(char *str);
int					line_is_comment(char *str);
int					is_label(char *str, int label_type);

/*
** utils2.c
*/

int					str_isdigit(char *str);
int					is_valid_instr(char *instr, t_line *line);

/*
** error.c
*/

void				error(char *error);

/*
** init_structs.c
*/

void				init_file(t_asm *file);
int					init_token(t_line *line, int start, int end);
int					init_line(t_asm *file, int line_type, char *str,
					int line_nb);

/*
** stock_file.c
*/

int					stock_file(t_asm *file, int fd);

/*
** parse_file.c
*/

int					parse_file(t_asm *file);

/*
** parse_token.c
*/

int					valid_params(t_line *line);
int					parse_token(t_token *token, t_line *line);

/*
** load_file.c
*/

int					load_file(t_asm *file);

/*
** get_bytecode_data.c
*/

int					get_to_load_data(t_asm *file);

/*
** label.c
*/

int					check_label(t_asm *file, t_list *line_list,
						t_line *lab_line, t_token *token);

/*
** stock_token_in_load.c
*/

int					stock_token_in_to_load(t_line *line, t_token *token,
											size_t *octet);

/*
** get_len_to_load.c
*/

int					get_len_to_load(t_line *line);

#endif

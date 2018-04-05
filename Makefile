# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavizet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 13:15:57 by gavizet           #+#    #+#              #
#    Updated: 2018/04/04 17:45:30 by gavizet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------| COLORS |-----------------------------------#
NOC				= \033[0m
BOLD			= \033[1m
BLINK			= \033[5m
UNDERLINE		= \033[4m
BLACK			= \033[0;30m
RED				= \033[38;5;196m
GREEN			= \033[38;5;46m
YELLOW			= \033[38;5;226m
BLUE			= \033[0;34m
VIOLET			= \033[0;35m
CYAN			= \033[0;36m
WHITE			= \033[1;37m
ORANGE			= \033[38;5;202m
#------------------------------------------------------------------------------#

#-------------------------------| COMPILATION |--------------------------------#
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
MAKE			= make -C
#------------------------------------------------------------------------------#

#-------------------------------| EXECUTABLE |---------------------------------#
ASM_NAME 		= asm
VM_NAME 		= corewar
#------------------------------------------------------------------------------#

#----------------------------------| PATH |------------------------------------#
LIBFT_PATH		= libft/
VM_SRC_PATH		= srcs/vm/
ASM_SRC_PATH	= srcs/asm/
OBJS_PATH		= objs/
VM_OBJS_PATH	= objs/vm/
ASM_OBJS_PATH	= objs/asm/
HEADERS_PATH	= includes/
#------------------------------------------------------------------------------#

#--------------------------------| ASM FILES |---------------------------------#
ASM_FILES		= asm.c\

ASM_HEAD_FILES	= asm.h\
#------------------------------------------------------------------------------#

#--------------------------------| VM FILES |----------------------------------#
VM_FILES		=	op.c \
					vm.c \
					vm_parse_process.c \
					debug_vm.c \
					vm_treat_args.c \
					prepare_memory.c \
					vm_launch.c \
					vm_handle_process.c \
					vm_handle_process2.c \
					vm_virtual_foam_bat.c \
					vm_check_champ.c \
					killemall.c \
					load.c \
					store.c \
					init_vm.c \
					ncurses.c \
					ncurses2.c \
					ncurses3.c	\
					add.c \
					sub.c \
					ld.c \
					st.c \
					and.c \
					or.c \
					xor.c \
					ldi.c \
					lld.c \
					lldi.c \
					sti.c \
					fork.c \
					aff.c \
					zjmp.c \
					live.c \
					get_param.c \
					is_reg.c \
					parse_verbose.c \
					advance_pc.c

VM_HEAD_FILE	= op.h\
				  vm.h\
				  colors.h\
#------------------------------------------------------------------------------#

#------------------------------| CREATE SOURCE |-------------------------------#
VM_SRC			= $(addprefix $(VM_SRC_PATH), $(VM_FILES))
ASM_SRC			= $(addprefix $(ASM_SRC_PATH), $(ASM_FILES))
#------------------------------------------------------------------------------#

#------------------------------| CREATE OBJECTS |------------------------------#
VM_OBJ			= $(addprefix $(VM_OBJS_PATH), $(VM_FILES:.c=.o))
ASM_OBJ			= $(addprefix $(ASM_OBJS_PATH), $(ASM_FILES:.c=.o))
#------------------------------------------------------------------------------#

#---------------------------------| INCLUDES |---------------------------------#
INCLUDES		= -I $(HEADERS_PATH)
VM_HEADERS		= $(addprefix $(INCLUDES_PATH), $(VM_HEAD_FILES))
ASM_HEADERS		= $(addprefix $(INCLUDES_PATH), $(ASM_HEAD_FILE))
#------------------------------------------------------------------------------#

#---------------------------------| LIBFT |------------------------------------#
INC_LIBFT		= -I $(LIBFT_PATH)
LIBFT			= -L $(LIBFT_PATH) -lft
#------------------------------------------------------------------------------#

.PHONY	:	libft all clean fclean re

#----------------------------------| RULES |-----------------------------------#
all: libft $(VM_NAME)

libft:
	@$(MAKE) $(LIBFT_PATH)

$(ASM_OBJS_PATH)%.o: $(ASM_SRC_PATH)%.c $(ASM_HEADERS) $(LIBFT_PATH)libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(ASM_OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCLUDES) $(INC_LIBFT) -o $@ -c $<
	@echo "$(notdir $@) ☑️ "

$(VM_OBJS_PATH)%.o: $(VM_SRC_PATH)%.c $(VM_HEADERS) $(LIBFT_PATH)libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(VM_OBJS_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -g $(INCLUDES) $(INC_LIBFT) -o $@ -c $<
	@echo "$(notdir $@) ☑️ "

$(ASM_NAME): $(ASM_OBJ)
	@$(CC) $(FLAGS) $(LIBFT) $(ASM_OBJ) -o $@
	@echo "✅  $(GREEN)[./$(ASM_NAME)] was successfully created ✅$(NOC)"

$(VM_NAME): $(VM_OBJ)
	@$(CC) -lncurses $(FLAGS) -g -fsanitize=address $(LIBFT) $(VM_OBJ) -o $@
	@echo "✅  $(GREEN)[./$(VM_NAME)] was successfully created ✅$(NOC)"

clean:
	@if [ -e $(OBJS_PATH) ];\
		then\
		$(MAKE) $(LIBFT_PATH) clean;\
		rm -rf $(OBJS_PATH);\
		echo "⚠️  $(YELLOW)Deleted object files from [$(OBJS_PATH)] ⚠️ $(NOC)";\
		fi;

fclean: clean
	@if [ -e $(VM_NAME) ];\
		then\
		$(MAKE) $(LIBFT_PATH) fclean;\
		rm -f $(VM_NAME);\
		echo "❌  $(RED)Deleted [./$(VM_NAME)] ❌$(NOC)";\
		fi;

re		: fclean all
#------------------------------------------------------------------------------#

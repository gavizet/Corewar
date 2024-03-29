# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavizet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/01 14:43:03 by gavizet           #+#    #+#              #
#*   Updated: 2017/06/07 14:10:06 by lgiacalo         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

#---------------------------------| COLORS |-----------------------------------#
NOC			= \033[0m
BOLD		= \033[1m
BLINK		= \033[5m
UNDERLINE	= \033[4m
BLACK		= \033[0;30m
RED			= \033[38;5;196m
GREEN		= \033[38;5;46m
YELLOW		= \033[38;5;226m
BLUE		= \033[0;34m
VIOLET		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[1;37m
ORANGE		= \033[38;5;202m
BG_WHITE	= \033[48;5;15m
BG_BLACK	= \033[48;5;0m
BG_GREEN	= \033[48;5;2m
VAR			= \033[38;5;
CLN			= \033[K
1LN			= \033[1A
#------------------------------------------------------------------------------#

#--------------------------------| LIBRARY |-----------------------------------#
NAME 		= libft.a
#------------------------------------------------------------------------------#

#-------------------------------| COMPILATION |--------------------------------#
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
#------------------------------------------------------------------------------#

#---------------------------------| INCLUDES |---------------------------------#
SRCS_PATH		= srcs/
OBJS_PATH		= objs/
INCLUDES_PATH	= includes/
#------------------------------------------------------------------------------#

#------------------------------| SOURCE FILES |--------------------------------#
SRCS_FILES	= printf/cast.c printf/check.c printf/utils.c					\
			  printf/ft_printf.c printf/parse_args.c printf/manage_int.c	\
			  printf/manage_char.c	printf/manage_hexa.c					\
			  printf/manage_octal.c printf/manage_wchar.c					\
			  printf/manage_binary.c printf/manage_string.c					\
			  printf/manage_percent.c printf/manage_pointer.c				\
			  printf/manage_uns_int.c	printf/manage_wstring.c				\
			  printf/get_conversion.c										\
			  lst/ft_lstadd.c lst/ft_lstcmp.c lst/ft_lstdel.c				\
			  lst/ft_lstmap.c lst/ft_lstnew.c lst/ft_lstrev.c				\
			  lst/ft_lstsize.c lst/ft_lstiter.c lst/ft_lstclear.c			\
			  lst/ft_lstprint.c	lst/ft_lstdelone.c lst/ft_lstaddback.c		\
			  lst/ft_lstrm.c lst/ft_lstrm_at.c lst/ft_lst_at.c				\
			  lst/ft_lstdelcontent.c										\
			  maths/ft_abs.c maths/ft_pow.c	maths/ft_atoi.c maths/ft_itoa.c	\
			  maths/ft_sqrt.c maths/ft_rec_fac.c maths/reverse_octet.c		\
			  maths/ft_itoa_base_uns.c maths/ft_itoa_base_signed.c			\
			  mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memchr.c				\
			  mem/ft_memcmp.c mem/ft_memdel.c mem/ft_memset.c				\
			  mem/ft_memccpy.c mem/ft_memmove.c	mem/free_tab2d.c			\
			  mem/ft_memalloc.c	mem/ft_exit_malloc_error.c					\
			  output/ft_putnbr.c output/ft_putstr.c output/ft_putchar.c		\
			  output/ft_putendl.c output/ft_putwchar.c						\
			  output/ft_putnwstr.c output/ft_putnbr_fd.c					\
			  output/ft_putstr_fd.c	output/ft_putendl_fd.c					\
			  output/ft_putchar_fd.c output/ft_putnbr_base.c				\
			  str/ft_strcat.c str/ft_strchr.c str/ft_strclr.c				\
			  str/ft_strcmp.c str/ft_strcpy.c str/ft_strdel.c				\
			  str/ft_strdup.c str/ft_strequ.c str/ft_strlen.c				\
			  str/ft_strmap.c str/ft_strnew.c str/ft_strrev.c				\
			  str/ft_strstr.c str/ft_strsub.c str/ft_strnstr.c				\
			  str/ft_strrchr.c str/ft_striter.c str/ft_strjoin.c			\
			  str/ft_strlcat.c str/ft_strtrim.c str/ft_wstrlen.c			\
			  str/ft_strmapi.c str/ft_strncat.c str/ft_strncmp.c			\
			  str/ft_strncpy.c str/ft_strnequ.c str/ft_striteri.c			\
			  str/ft_strisint.c												\
			  str/ft_strsplit.c str/ft_str_isdigit.c str/ft_calc_wstrlen.c	\
			  utils/ft_swap.c utils/ft_isalnum.c utils/ft_isalpha.c			\
			  utils/ft_isascii.c utils/ft_isdigit.c							\
			  utils/ft_islower.c utils/ft_isprint.c utils/ft_isupper.c		\
			  utils/ft_error.c utils/ft_isdigitstr.c						\
			  utils/ft_tolower.c utils/ft_toupper.c utils/get_next_line.c
#------------------------------------------------------------------------------#

#-------------------------------| HEADER FILES |-------------------------------#
HEAD_FILES	= printf.h lst.h maths.h mem.h output.h str.h utils.h
#------------------------------------------------------------------------------#

#------------------------------| CREATE SOURCE |-------------------------------#
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
#------------------------------------------------------------------------------#

#------------------------------| CREATE OBJECTS |------------------------------#
OBJS_DIRS	= $(addprefix $(OBJS_PATH), printf/ mem/ output/ lst/ str/ utils/ maths/)
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))\
#------------------------------------------------------------------------------#

#--------------------------------| INCLUDES |----------------------------------#
INCLUDES	= -I $(INCLUDES_PATH)
HEADERS		= $(addprefix $(INCLUDES_PATH), $(HEAD_FILES))
#------------------------------------------------------------------------------#
.PHONY	:	all clean fclean re

#-------------------------------| PROGRESS BAR |-------------------------------#
INDEX		= 0
NB_FUNC		= $(words $(SRCS_FILES))
#------------------------------------------------------------------------------#

#----------------------------------| RULES |-----------------------------------#
all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS)
		@mkdir $(OBJS_PATH) 2> /dev/null || true
		@mkdir $(OBJS_DIRS) 2> /dev/null || true
		@$(CC) $(FLAGS) -g $(INCLUDES) -o $@ -c $<
		@$(eval COMPILED=$(shell echo $$(($(INDEX)*30/$(NB_FUNC)))))
		@$(eval LEFT=$(shell echo $$((30-$(INDEX)*30/$(NB_FUNC) - 1))))
		@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB_FUNC)))))
		@$(eval COLOR=$(shell list=(160 196 202 208 215 221 226 227 190 154 118 82 46); color=$$(($(PERCENT) * $${#list[@]} / 100)); echo "$${list[$$color]}"))
		@printf "\r $(VAR)$(COLOR)m$(PERCENT)%%$(NOC) |`printf '$(VAR)$(COLOR)m█%.0s' {0..$(COMPILED)}``printf ' %.0s' {0..$(LEFT)}`$(NOC)| $(notdir $@)... ☑️  $(CLN)"
		@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@printf "\r$(CLN)$(GREEN)✅  [$(NAME)] was succesfully created ✅$(NOC)\n"

clean:
		@if [ -e $(OBJS_PATH) ];\
		then\
			rm -rf $(OBJS);\
			rmdir $(OBJS_DIRS) 2> /dev/null || true;\
			rmdir $(OBJS_PATH) 2> /dev/null || true;\
			echo "\r$(YELLOW)⚠️  Deleted object files from [libft/$(OBJS_PATH)] ⚠️ \033[0m\033[K";\
		fi;

fclean: clean
		@if [ -e $(NAME) ];\
		then\
			rm -rf $(NAME);\
			echo "\r$(RED)❌  Deleted [$(NAME)] ❌\033[0m\033[K";\
		fi;

re: fclean all
#------------------------------------------------------------------------------#

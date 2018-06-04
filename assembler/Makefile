# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 19:18:37 by ltanenba          #+#    #+#              #
#    Updated: 2018/05/29 15:50:19 by jgelbard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= asm

CC			= gcc

# -g for lldb
DEBUG		= #-g

HEADERS = libft.h asm.h corewar.h arena.h op.h
INC_DIRS = includes ../corewar/includes ../libft/includes
OBJ = asm.o print_bytes.o \

VPATH = $(INC_DIRS) src ../corewar/src ../libft
CFLAGS = -Wall -Werror -Wextra $(addprefix -I, $(INC_DIRS)) $(DEBUG)

.INTERMEDIATE: $(OBJ)
.SILENT:
# ---------------------------------------------------------------------------- #

all: print $(NAME)
$(OBJ): $(HEADERS) libft.a

print:
	@printf "%b" "$(LIB_COLOR)Compiling: $(OK_COLOR)$(NAME)\n$(NO_COLOR)"

$(NAME): libft.a $(OBJ)

libft.a:
	@make -C ../libft

clean:
	@printf "Cleaning up $(NAME)...\n"
	rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C ../libft fclean

re: fclean
	make -C ../libft
	make

.PHONY: clean fclean all re print

OK_COLOR       = \033[38;5;105;1m
LIB_COLOR      = \033[1;32m
NO_COLOR    = \033[m

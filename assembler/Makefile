# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 19:18:37 by ltanenba          #+#    #+#              #
#    Updated: 2018/05/29 11:36:31 by jgelbard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= asm

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
INC_FLAGS	= -I libft_leo/includes -I includes

# -g for lldb
DEBUG		= #-g

# Cosmetics Section:

OK_COLOR	= \033[38;5;105;1m
OBJ_COLOR	= \033[38;5;208m
COM_COLOR	= \033[38;5;200m
LIB_COLOR	= \033[1;32m
NO_COLOR    = \033[m

COM_STRING	= "Compiling:"

# End Cosmetics.

LIB_LEO		= libft_leo/libft.a

LIBS		= $(LIB_LEO)

# Add header files here: (use full relative path to Makefile)
INCLUDES	= libft_leo/includes/libft.h \
			  includes/asm.h \
			  includes/corewar.h \
			  includes/arena.h \
			  includes/op.h \
			  ../shared/includes/libft/libft.h \
			  ../shared/includes/shared_util.h \


# Add source files here: (files assumed to be in ./src folder)
FILES		= main.c

SRC			= $(addprefix src/, $(FILES))
SRC			+= ../corewar/src/dev_util.c #FIXME utils should be shared
OBJ			= $(addprefix obj/, $(FILES:.c=.o))

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(LIB_LEO) $(SRC)
	@printf "%b" "$(LIB_COLOR)Compiling: $(OK_COLOR)$@\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) $(INC_FLAGS) -o $(NAME) $(SRC) $(LIBS)

$(LIB_LEO):
	@make -C libft_leo

clean:
	@printf "Cleaning up $(NAME)...\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft_leo fclean

obj:
	@printf "Creating obj/ directory...\n"
	@mkdir obj/

obj/%.o: $(SRC) | obj
	@printf "%b" "$(COM_COLOR)  $(COM_STRING) $(OBJ_COLOR)$@\n$(NO_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

norm:
	@printf "%b" "$(LIB_COLOR)Checking Norm...\n$(NO_COLOR)"
	@norminette $(SRC) $(INCLUDES)

.PHONY: clean fclean all re

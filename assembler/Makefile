# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgelbard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/31 14:41:52 by jgelbard          #+#    #+#              #
#    Updated: 2018/05/31 17:25:37 by jgelbard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRC = $(NAME).c \
	  print_util.c \
	  asm_test.c \
	  util.c \

SOURCE_DIRS = src ../corewar/src
INCLUDE_DIRS = includes ../corewar/includes libft/includes
LIB_DIRS = libft
LDLIBS = -lft

CFLAGS = -Wall -Wextra -Werror

# --------------------------------------------------------------------------- #

CC = gcc
CPPFLAGS += $(addprefix -I, $(INCLUDE_DIRS))
LDFLAGS += $(addprefix -L, $(LIB_DIRS))
OUTPUT_OPTION += -MMD -MP

BUILD_DIR = build
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))
DEPEND_FILES = $(OBJ:.o=.d)

vpath %.c $(SOURCE_DIRS)
vpath %.d $(BUILD_DIR)
vpath %.o $(BUILD_DIR)
vpath %.h $(INCLUDE_DIRS)
vpath %.a $(LIB_DIRS)

# --------------------------------------------------------------------------- #

all: $(LIB_DIRS) $(NAME)

$(NAME): $(OBJ)
	$(LINK.c) -o $@ $(LDLIBS) $^

$(OBJ): $(BUILD_DIR)/%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) -c $< -o $@

$(LIB_DIRS):
	make -C $@

clean:
	rm -f $(OBJ) $(DEPEND_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.PHONY: $(LIB_DIRS)

# --------------------------------------------------------------------------- #

-include $(DEPEND_FILES)

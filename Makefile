# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2016/12/08 14:24:44 by mvlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC_DIR = ./
OBJ_DIR = ./
INC_DIR = ./
LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a

OBJ	=   check.o \
		fillit_core.o \
		fillit_find_dot.o \
		fillit.o \
		ft_bzero2.o \
		ft_memalloc2.o \
		map_control.o \
		map_delete.o \
		map_generate.o \
		map_print.o \
		map_size.o \
		save_line.o \
		tetromino_delete.o \
		tetromino_set.o


LIB = $(LIB_DIR)libft.a

HEADERS	= $(INC_DIR)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC_OPT = -I $(LIB_INC) -I $(INC_DIR)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c

RMF 	= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C ./libft/
	$(CC) $(CFLAGS) $(LIB_LIB) $^ $(OUT_OPT) $(NAME)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	cd $(LIB_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re

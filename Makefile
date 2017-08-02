# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 13:09:11 by wlin              #+#    #+#              #
#    Updated: 2017/08/02 12:11:43 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a

LIB_DIR = libft/
SRC_DIR = src/
BUILD_DIR = build/
INC_DIR = include/

SRC_FILE = \
stack_op \
checker


SRC = \
$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILE)))

OBJ = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILE)))

all: $(NAME)

$(NAME):  $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ -I libft/libft.h -L./libft -lft
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -o $@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

$(LIBFT):
	@make -C ./libft

clean:
	@rm -rf $(BUILD_DIR);
	@cd libft && $(MAKE) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

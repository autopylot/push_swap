# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/28 13:09:11 by wlin              #+#    #+#              #
#    Updated: 2017/08/16 11:38:44 by wlin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a

LIB_DIR = libft/
SRC_DIR = src/
BUILD_DIR = build/
INC_DIR = include/

CHECKER_FILES = \
checker \
stack_op1 \
stack_op2 \
parse_input \
read_instr \
utility_func \
find_value

CHECKER_SRC = \
$(addprefix $(SRC_DIR), $(addsuffix .c, $(CHECKER_FILES)))

CHECKER_OBJ = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(CHECKER_FILES)))

PUSH_SWAP_FILES = \
push_swap \
stack_op1 \
stack_op2 \
parse_input \
sort_algorithms \
partial_sort \
find_optimal \
find_value \
find_rotate \
find_median \
utility_func


PUSH_SWAP_SRC = \
$(addprefix $(SRC_DIR), $(addsuffix .c, $(PUSH_SWAP_FILES)))

PUSH_SWAP_OBJ = \
$(addprefix $(BUILD_DIR), $(addsuffix .o, $(PUSH_SWAP_FILES)))

all:

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) -o $@ -I libft/libft.h -L./libft -lft
	@echo "\033[32mExecutable \033[1;32m$(PUSH_SWAP)\033[1;0m\033[32m created.\033[0m"

$(CHECKER):  $(CHECKER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CHECKER_OBJ) -o $@ -I libft/libft.h -L./libft -lft
	@echo "\033[32mExecutable \033[1;32m$(CHECKER)\033[1;0m\033[32m created.\033[0m"

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

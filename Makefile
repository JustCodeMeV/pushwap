# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/02 16:25:35 by vrouxel           #+#    #+#              #
#    Updated: 2026/09/20 21:30:05 by vrouxel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -Iinclude -Ilib/libft -Ilib/lists
BUILD_DIR := build
LIST_DIR := lib/lists
LIST_LIB := lib/liblists.a
LIBFT_DIR := lib/libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

SRC := src/main.c \
	src/parsing/disorder.c \
	src/parsing/parsing.c \
	src/parsing/parsing_helpers.c \
	src/instructions/instruction_set.c \
	src/instructions/instruction_rotate.c \
	src/instructions/instruction_reverse.c \
	src/run/run.c \
	src/run/run_create.c \
	src/run/run_operations.c \
	src/run/run_operations_push.c \
	src/run/run_operations_reverse.c \
	src/run/run_operations_rotate.c \
	src/sorters/bubblesort.c \
	src/sorters/smallsort.c \
	src/sorters/mediumsort.c \
	src/sorters/radixsort.c
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB) $(LIST_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(LIST_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(LIST_LIB):
	$(MAKE) -C $(LIST_DIR)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIST_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIST_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

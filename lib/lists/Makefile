# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/05 19:05:00 by vrouxel           #+#    #+#              #
#    Updated: 2026/09/20 21:30:05 by vrouxel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := liblists.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I. -I../ft_printf
BUILD_DIR := build

SRC := lists.c \
	lists_insert.c \
	lists_manage.c \
	lists_private.c \
	lists_query.c \
	lists_traverse.c \
	lists_print.c 
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

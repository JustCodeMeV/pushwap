# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrouxel <vrouxel@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/23 14:35:27 by vrouxel           #+#    #+#              #
#    Updated: 2026/09/20 21:30:05 by vrouxel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libftprintf.a

BUILD_DIR   := build
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
SRCS        := ft_printf.c ft_printf_utils.c ft_printf_base.c

OBJS        := $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

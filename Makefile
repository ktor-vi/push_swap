# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vphilipp <vphilipp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 17:31:20 by vphilipp          #+#    #+#              #
#    Updated: 2023/08/23 19:44:17 by vphilipp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)

OBJS = $(SRCS:.c=.o)

INC = -I $(INC_DIR) -I $(LIBFT_DIR)

LIBS = -L $(LIBFT_DIR) -lft

NAME = push_swap

all: $(NAME)


$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) libft.a -o $@ 


%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


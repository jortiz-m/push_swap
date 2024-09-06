# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 11:38:37 by jortiz-m          #+#    #+#              #
#    Updated: 2024/09/06 12:50:37 by jortiz-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a
LIBFT = libft/
INCLUDE = -L .libft/ -lft

FUNCTIONS = 
FUNCTIONS_PS = push_swap/push_swap.c

OBJECT = $(FUNCTIONS:%.c=%.o)
OBJECT_PS = $(FUNCTIONS_PS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJECT) $(OBJECT_PS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECT) $(OBJECT_PS) -o $(NAME) $(INCLUDE)
	@echo "Compiled successfully bro!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	@make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
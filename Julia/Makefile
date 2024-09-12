NAME = pushswap
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDE = -I $(LIBFT_DIR) -I .

FUNCTIONS = push_swap.c error.c opti_to_the_top.c sort_utils.c sort.c \
			init_stacks.c stack_utils.c push.c reverse_rotate.c rotate.c \
			show_moves.c swap.c chunk_moves.c chunk_sort.c chunk_split.c \
			chunk_utils.c

OBJECT = $(FUNCTIONS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(OBJECT) $(LIBFT)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJECT) -o $(NAME) -L $(LIBFT_DIR) -lft $(INCLUDE)
	@echo "Compiled successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
NAME = push_swap
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDE = -I $(LIBFT_DIR) -I .

SRC_DIRS = . chunk moves
SRC_FILES = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

OBJECT = $(SRC_FILES:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJECT) -o $(NAME) -L $(LIBFT_DIR) -lft
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
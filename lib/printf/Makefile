NAME = ft_printf.a

FUNCTIONS = ft_printf.c ft_putnbr.c ft_puthex.c ft_putunsignbr.c \
			ft_putchar.c ft_putstr.c ft_hexapointer.c \

OBJECT = $(FUNCTIONS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
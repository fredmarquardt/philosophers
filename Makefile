CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
SOURCE = main.c create_philos.c allocate_free.c
OBJ = $(SOURCE:.c=.o)
NAME = philo
FTPRINTF	= ./ft_printf/libftprintf.a
LIBFT		= ./libft/libft.a

all: $(NAME)

$(NAME):  $(FTPRINTF) $(LIBFT) $(OBJ)
	$(CC) $(SOURCE) $(CFLAGS) $(FTPRINTF) $(LIBFT) -o $(NAME)

$(FTPRINTF):
	@git submodule init ft_printf
	@git submodule update ft_printf
	@cd ft_printf && make && make clean

$(LIBFT):
	@git submodule init libft
	@git submodule update libft
	@cd libft && make && make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re

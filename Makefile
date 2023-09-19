CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
SOURCE = main.c create_philos.c tischlein_deck_dich.c eat_sleep_repeat.c clean_table.c utils.c
OBJ = $(SOURCE:.c=.o)
NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SOURCE) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re

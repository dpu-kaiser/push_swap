NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) -I. $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -I. $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

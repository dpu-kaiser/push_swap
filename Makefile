NAME = push_swap

LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c input_handling.c stack_utils.c command_handling.c sorting.c stack_optimization.c cmd_optimization.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

LIB_DIR = $(LIBFT)
LIB = ft

all: $(NAME)

$(NAME): $(OBJ_FILES) | libft
	$(CC) $(CFLAGS) -I. -L$(LIB_DIR) -l$(LIB) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ_FILES)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

libft:
	make all bonus -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean libft re

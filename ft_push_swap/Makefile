NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap.c libft_helpers3.c simple_algorithm.c parsing.c medium_algorithm.c medium_algorithm_utils.c op_swap.c op_push.c op_rotate.c op_rev_rotate.c \
complex_algorithm.c split.c disorder.c bench_mark.c libft_helpers.c libft_helpers2.c core_swap.c core_push.c core_rotate.c core_rev_rotate.c parsing_utils.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SRC=ft_printf.c ft_putaddr.c ft_putchar.c ft_puthex.c ft_puthexx.c ft_putint.c ft_putstr.c  ft_putuint.c ft_strchr.c

OBJ = $(SRC:.c=.o)

all:$(NAME)
$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
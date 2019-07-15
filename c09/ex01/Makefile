SRCDIR = srcs
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ = $(SRC:.c = .o)
INCLUDEDIR = includes
INCLUDES = ft.h
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
OUT = libft.a

all: OUT
.PHONY: all

$(OUT): $(OBJ)
	ar -crs $(OBJ)

$(OBJ): %.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f srcs/*.o

.PHONY: fclean
fclean: clean
	rm $(OUT)

.PHONY: re
re: fclean all

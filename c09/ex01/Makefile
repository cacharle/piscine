OUT = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
OBJ = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	ar -crs $(OUT) $(OBJ)

srcs/ft_putchar.o: srcs/ft_putchar.c includes/ft.h
	$(CC) $(CCFLAGS) -c $< -o $@

srcs/ft_swap.o: srcs/ft_swap.c includes/ft.h
	$(CC) $(CCFLAGS) -c $< -o $@

srcs/ft_putstr.o: srcs/ft_putstr.c includes/ft.h
	$(CC) $(CCFLAGS) -c $< -o $@

srcs/ft_strlen.o: srcs/ft_strlen.c includes/ft.h
	$(CC) $(CCFLAGS) -c $< -o $@

srcs/ft_strcmp.o: srcs/ft_strcmp.c includes/ft.h
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(OUT)

.PHONY: re
re: fclean all

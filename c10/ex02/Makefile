# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 14:50:02 by cacharle          #+#    #+#              #
#    Updated: 2019/07/19 06:47:44 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = ft_tail
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
SRC = main.c file.c handle_error.c helper.c
OBJ = $(SRC:.c=.o)

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.c include.h
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: clean
fclean: clean
	rm -f $(OUT)

.PHONY: re
re: fclean all

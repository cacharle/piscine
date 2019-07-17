# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 07:55:23 by cacharle          #+#    #+#              #
#    Updated: 2019/07/17 08:15:25 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = do-op
CC = gcc
FLAGS = -Wall -Wextra #-Werror
SRC = main.c operators.c parse.c helper.c
OBJ = $(SRC:.c=.o)

.PHONY: all
all : $(OUT)

$(OUT): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c include.h
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(OUT)

.PHONY: re
re: fclean all

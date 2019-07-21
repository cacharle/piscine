# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/20 07:26:11 by cacharle          #+#    #+#              #
#    Updated: 2019/07/21 11:46:43 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = rush-02
SRC = main.c helper.c parse.c error.c dict.c convert.c
OBJ = $(SRC:.c=.o)

CC = gcc
CCFLAGS = -Wall -Wextra #-Werror

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(OUT)

%.o: %.c include.h
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(OUT)

.PHONY: re
re: fclean all

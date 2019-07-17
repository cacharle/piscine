# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 14:50:14 by cacharle          #+#    #+#              #
#    Updated: 2019/07/16 14:50:19 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = ft_cat
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
SRC = main.c io.c helper.c
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


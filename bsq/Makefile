# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 12:09:54 by cacharle          #+#    #+#              #
#    Updated: 2019/07/19 15:18:19 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = bsq
SRCDIR = srcs
SRC = $(SRCDIR)/main.c
OBJ = $(SRC:.c=.o)
INCLUDES = includes/include.h

CC = gcc
CCFLAGS = -Wall -Wextra #-Werror
LDFLAGS = -Iincludes

ARGS = 10 10 2

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) $(LDFLAGS) -c -o $@ $<

.PHONY: clean
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(OUT)

.PHONY: re
re: fclean all

.PHONY: generate
generate:
	./tests/generate.pl ${ARGS}

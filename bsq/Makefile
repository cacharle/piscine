# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/19 12:09:54 by cacharle          #+#    #+#              #
#    Updated: 2019/07/24 17:47:26 by cacharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = main.c algo.c helper.c terrain.c parse.c parse_helper.c utils.c
OBJ = $(SRC:.c=.o)
INCLUDES = include.h

CC = cc
CCFLAGS = -Wall -Wextra -Werror

ARGS = 10 10 2

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

%.o: %.c $(INCLUDES)
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: generate
generate:
	@./tests/generate.pl ${ARGS}

.PHONY: test
test: all
	@./tests/generate.pl ${ARGS} > ./tests/boardtest
	@./$(NAME) ./tests/boardtest

.PHONY: flex
flex:
	@./tests/generate.pl 360 80 100000 > tests/printable
	@./bsq ./tests/printable

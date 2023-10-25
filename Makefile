# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 17:11:29 by lnarvaez          #+#    #+#              #
#    Updated: 2023/07/27 17:11:34 by lnarvaez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM	= rm -f
CC	= gcc
CCFLAGS	= -Wextra -Werror -Wall

NAME = push_swap
SRC = $(wildcard *.c utils/*.c)

OBJ = $(SRC:.c=.o)



$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 22:13:06 by esilva-s          #+#    #+#              #
#    Updated: 2023/06/24 23:06:10 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = teste_gnl
CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I get_next_line.h
SRC = teste.c get_next_line.c get_next_line_utils.c
OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG) 
	$(CC) $(FLAGS) $(OBG) -o $(NAME)

$(OBG): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all
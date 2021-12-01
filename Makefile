# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 00:50:16 by abarchil          #+#    #+#              #
#    Updated: 2021/12/01 16:02:20 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c ft_check_error.c src/ft_memmove.c src/ft_strlen.c src/ft_strdup.c src/ft_strjoin.c src/ft_split.c src/ft_memcpy.c \
src/ft_strncmp.c ft_child_process.c ft_parent_process.c ft_check_command.c

OBJ_FILE = $(SRC_FILE:.c=.o)

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

all :	$(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ_FILE)
	$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
clean:
	rm $(OBJ_FILE)

fclean:	clean
	rm $(NAME)

re : fclean all

.PHONY : clean fclean all re

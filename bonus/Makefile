# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 00:50:16 by abarchil          #+#    #+#              #
#    Updated: 2021/12/02 16:14:22 by abarchil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = main.c ft_check_error.c src/ft_memmove.c src/ft_strlen.c src/ft_strdup.c src/ft_strjoin.c src/ft_split.c src/ft_memcpy.c \
src/ft_strncmp.c ft_child_process.c ft_parent_process.c ft_check_command.c

OBJ_FILE = $(SRC_FILE:.c=.o)

NAME = pipex

BLUE=\033[0;34m

GREEN=\033[0;32m

ORANG=\033[0;33m

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

all :	$(NAME)

%.o : %.c
	@echo "$(GREEN)--------COMPILING $<"
	@$(CC) -c $< -o $@

$(NAME): $(OBJ_FILE)
	@echo "     $(ORANG)*********************"
	@echo "     $(ORANG)*                   *"
	@echo "     $(ORANG)*   PIPEX IS REASY  *"
	@echo "     $(ORANG)*                   *"
	@echo "     $(ORANG)*********************"
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
clean:
	@rm $(OBJ_FILE)
	@echo "\n$(BLUE)REMOVING OBJECT_FILES DONE\n"

fclean:	clean
	rm $(NAME)

re : fclean all

.PHONY : clean fclean all re

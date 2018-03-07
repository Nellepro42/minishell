# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neprocur <neprocur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/26 01:33:05 by neprocur          #+#    #+#              #
#    Updated: 2015/10/18 03:26:38 by neprocur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1
SRC = ./ft_minishell1.c ./get_next_line.c ft_unsetenv.c tablen.c \
	  ft_setenv.c ft_search.c write_env.c ft_cd.c ft_setenv_option.c \
	  check_path.c check_the_check.c ft_builtins.c epur_cmd.c prompt.c \
	  split_env.c ft_move_oldpwd.c ft_while.c setenv_cd.c \
	  ft_setenv_cd_option.c ft_args.c ft_search_i.c ft_next2.c \

LIBFT = libft/libft.a
CC = gcc
LFLAGS = -L libft/ -lft
FLAG = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	make -C libft
	gcc $(FLAG) $(LFLAGS)  -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c ./ft_minishell1.h
		@$(CC) -o $@ -c $< $(FLAGS)


clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

.PHONY: clean fclean

re: fclean all


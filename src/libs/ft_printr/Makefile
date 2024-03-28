# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 13:10:44 by aeddaoud          #+#    #+#              #
#    Updated: 2022/06/16 13:01:40 by aeddaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
INCLUDE=-I include
SRC=src/ft_printr.c src/ft_utils.c
FLAGS=$(INCLUDE) -Wall -Werror -Wextra -c
O_SRC=$(SRC:%.c=%.o)
NAME=libftprintr.a

all: $(NAME)

$(NAME): $(O_SRC)

%.o:%.c
	$(CC) $(FLAGS) $< -o $@
	ar -rc $(NAME) $@

clean:
	rm -rf src/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

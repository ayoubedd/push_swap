# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaoud <aeddaoud@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 05:01:26 by aeddaoud          #+#    #+#              #
#    Updated: 2022/07/19 14:29:56 by aeddaoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Werror -Wextra
LIBFT			=	ft_atoi.c ft_calloc.c ft_itoa.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c
FT_PRINTF		=	ft_printf.c ft_utils.c
FT_PRINTR		=	ft_printr.c ft_utils.c
GET_NEXT_LINE	=	get_next_line.c get_next_line_utils.c

# Mandatory
TARGET			=	push_swap
INCLUDE			=	-I libs/libft/include -I libs/ft_printf/include -I libs/ft_printr/include -I mandatory/include
PARSING			=	extract_numbers.c parser.c
SORTING			=	build_chunks.c first_phase.c helpers.c mode_3_helpers.c mode_5_helpers.c second_phase.c small_numbers.c sort_numbers.c sorter.c which_way.c
CHECKING		=	check_duplicate.c check_overflow.c check_sorted.c check_syntax.c checker.c
OPTIMIZING		=	optimizing.c
INSTRACTIONS	=	helpers.c log_instraction.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c
SRC				=	mandatory/src/main.c \
					$(addprefix libs/libft/src/, $(LIBFT)) \
					$(addprefix libs/ft_printf/src/, $(FT_PRINTF)) \
					$(addprefix libs/ft_printr/src/, $(FT_PRINTR)) \
					$(addprefix mandatory/src/parsing/, $(PARSING)) \
					$(addprefix mandatory/src/sorting/, $(SORTING)) \
					$(addprefix mandatory/src/checking/, $(CHECKING)) \
					$(addprefix mandatory/src/optimizing/, $(OPTIMIZING)) \
					$(addprefix mandatory/src/instructions/, $(INSTRACTIONS))
OBJ=$(SRC:%.c=%.o)

# Bonus
TARGET_BONUS		=	checker
INCLUDE_BONUS		=	-I libs/libft/include -I libs/ft_printf/include -I libs/ft_printr/include -I libs/get_next_line/include -I bonus/include
PARSING_BONUS		=	arguments_parser.c helpers.c instractions_parser.c parser.c
SORTING_BONUS		=	sorter.c
CHECKING_BONUS		=	check_duplicate.c check_overflow.c check_sorted.c check_syntax.c checker.c sorted_check.c
INSTRACTIONS_BONUS	=	helpers.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c
SRC_BONUS			=	bonus/src/main.c \
						$(addprefix libs/libft/src/, $(LIBFT)) \
						$(addprefix libs/ft_printf/src/, $(FT_PRINTF)) \
						$(addprefix libs/ft_printr/src/, $(FT_PRINTR)) \
						$(addprefix libs/get_next_line/src/, $(GET_NEXT_LINE)) \
						$(addprefix bonus/src/parsing/, $(PARSING_BONUS)) \
						$(addprefix bonus/src/sorting/, $(SORTING_BONUS)) \
						$(addprefix bonus/src/checking/, $(CHECKING_BONUS)) \
						$(addprefix bonus/src/instructions/, $(INSTRACTIONS_BONUS))
OBJ_BONUS=$(SRC_BONUS:%.c=%.o)

all: $(TARGET)

bonus: $(TARGET_BONUS)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) -o $(TARGET)

$(TARGET_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(INCLUDE_BONUS) $(OBJ_BONUS) -o $(TARGET_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(TARGET) $(TARGET_BONUS)

re: fclean all

mandatory/src/%.o:mandatory/src/%.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

bonus/src/%.o:bonus/src/%.c
	$(CC) $(FLAGS) $(INCLUDE_BONUS) -c $< -o $@

libs/get_next_line/src/%.o:libs/get_next_line/src/%.c
	$(CC) $(FLAGS) -I libs/get_next_line/include -D BUFFER_SIZE=5 -c $< -o $@

libs/libft/src/%.o:libs/libft/src/%.c
	$(CC) $(FLAGS) -I libs/libft/include -c $< -o $@

libs/ft_printf/src/%.o:libs/ft_printf/src/%.c
	$(CC) $(FLAGS) -I libs/ft_printf/include -c $< -o $@

libs/ft_printr/src/%.o:libs/ft_printr/src/%.c
	$(CC) $(FLAGS) -I libs/ft_printr/include -c $< -o $@
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sorin <sorin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 19:08:50 by sopopa            #+#    #+#              #
#    Updated: 2022/12/29 23:39:49 by sorin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

NAME_BONUS = get_next_line_bonus.a

SRCS = get_next_line.c \
	get_next_line_utils.c


FLAGS =	-Wall -Werror -Wextra

CC = gcc

OBJS = $(SRCS:.c=.o)

BONUS = get_next_line_bonus.c \
	get_next_line_utils_bonus.c 
	
	
OBJS_BONUS = $(BONUS:.c=.o)

$(NAME):
	$(CC) -c $(FLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)
	rm *.o

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bonus:
	$(CC) -c $(FLAGS) $(BONUS)
	ar rcs get_next_line_bonus.a $(OBJS_BONUS)
	rm *.o
	
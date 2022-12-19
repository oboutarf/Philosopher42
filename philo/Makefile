# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 00:47:46 by oboutarf          #+#    #+#              #
#    Updated: 2022/12/19 12:37:37 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo

CC 				= gcc -Wall -Wextra -Werror -g3

OBJ				= $(SRCS:.c=.o)

SRCS 			= main/main.c \

SRCH_INCLDS 	= -Iincld

RM				= rm -rf

BIN 			= prog


all:        $(NAME)

%.o: %.c
			$(CC) $(SRCH_INCLDS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:     clean
			$(RM) $(NAME)

re:         fclean $(NAME)

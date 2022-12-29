# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 00:47:46 by oboutarf          #+#    #+#              #
#    Updated: 2022/12/29 23:30:00 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo

CC 				= gcc -Wall -Wextra -Werror -pthread -g3

OBJ				= $(SRCS:.c=.o)

SRCS 			= main/main.c \
					srcs/free.c \
				  	srcs/libft.c \
					srcs/parsing.c \
					srcs/inits.c \
					srcs/routine.c \
					srcs/print.c \

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


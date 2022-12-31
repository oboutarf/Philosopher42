# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 00:47:46 by oboutarf          #+#    #+#              #
#    Updated: 2023/01/01 00:27:49 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo

CC 				= fsantize=address gcc -Wall -Wextra -Werror -pthread -g3

OBJ				= $(SRCS:.c=.o)

SRCS 			= main/main.c \
					srcs/free.c \
					srcs/time.c \
					srcs/dead.c \
				  	srcs/libft.c \
					srcs/inits.c \
					srcs/print.c \
					srcs/parsing.c \
					srcs/routine.c \
					srcs/message.c \
					srcs/actions.c \

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


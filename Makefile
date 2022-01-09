# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryosukearima <ryosukearima@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 16:00:52 by ryosukearim       #+#    #+#              #
#    Updated: 2022/01/08 23:27:05 by ryosukearim      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_printf.c \
		srcs/ft_printf_utils.c \
		srcs/ft_printf_utils2.c\
		srcs/ft_printf_utils3.c

OBJS = ${SRCS:%.c=%.o}

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all		: ${NAME}

%.o		:%.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

${NAME} :${OBJS}
		ar rcs ${NAME} ${OBJS}

clean 	:
		${RM} ${OBJS} ${OBJS_B}

fclean 	:clean
		${RM} ${NAME}

re 		:fclean all

.PHONY	:all clean fclean re bonus

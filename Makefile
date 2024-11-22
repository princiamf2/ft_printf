# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 18:12:40 by mm-furi           #+#    #+#              #
#    Updated: 2024/10/08 13:01:32 by mm-furi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
FLAG = -Wall -Werror -Wextra
SRCS = ft_print_hex.c ft_print_ptr.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunsigned.c
LIB = ranlib
AR = ar rcs
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)
	
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re .c.o

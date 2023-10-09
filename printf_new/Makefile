# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 10:55:44 by mmezzat           #+#    #+#              #
#    Updated: 2022/11/17 13:56:52 by mmezzat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_printf.c print_any_char.c print_any_num.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all 

.PHONY: fclean clean all re
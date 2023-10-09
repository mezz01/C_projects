# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 06:27:07 by mmezzat           #+#    #+#              #
#    Updated: 2023/09/29 05:41:23 by mmezzat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	actions.c five_sort.c ft_atoi.c ft_isdigit.c ft_split.c ft_strdup.c \
		ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_substr.c limited_nums_sort.c \
		main.c parse_arg.c push_swap.c radix_algorithm.c stacks_init.c \
		rotate.c reverse_rotate.c push.c swap.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

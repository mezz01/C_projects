# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 22:21:56 by mmezzat           #+#    #+#              #
#    Updated: 2022/11/15 13:20:55 by mmezzat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRC = ft_bzero.c  \
ft_isalpha.c \
ft_isdigit.c \
ft_memchr.c \
ft_memcpy.c \
ft_memset.c \
ft_strlcat.c \
ft_strlen.c \
ft_strnstr.c \
ft_putstr_fd.c \
ft_tolower.c \
ft_strrchr.c \
ft_toupper.c \
ft_atoi.c \
ft_strjoin.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_memcmp.c \
ft_memmove.c \
ft_strchr.c \
ft_strlcpy.c \
ft_strncmp.c \
ft_calloc.c \
ft_split.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_itoa.c \
ft_putnbr_fd.c \
ft_strmapi.c \
ft_strtrim.c \
ft_substr.c \
ft_striteri.c \
ft_strdup.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
%.o: %.c libft.h
		$(CC) $(CFLAGS) -o $@ -c $<
all: $(NAME)
clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY: clean fclean re all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 07:36:11 by mmezzat           #+#    #+#              #
#    Updated: 2023/09/16 06:32:26 by mmezzat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CLEAN=rm -rf
FLAGS= -Wall -Wextra -Werror 
LINKS= -lmlx -framework OpenGL -framework AppKit
SRC= check_content.c check_map.c ft_putnbr_fd.c ft_split.c ft_strdup.c\
ft_strncmp.c game_mlx.c gameplay.c get_next_line_utils.c get_next_line.c\
map.c messages.c movement_keys.c so_long.c is_solvable.c 
OBJ=${SRC:.c=.o}

NAME=so_long

all: ${NAME}

${NAME}:${OBJ}
	${CC} ${FLAGS} ${OBJ} ${LINKS} -o ${NAME}

%.o: %.c  so_long.h
	${CC} ${FLAGS} -c $<

clean:
	${CLEAN} ${OBJ}

fclean: clean
	${CLEAN} ${NAME}

re: fclean all

.PHONY: all clean fclean re

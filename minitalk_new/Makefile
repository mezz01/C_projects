# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 09:02:09 by mmezzat           #+#    #+#              #
#    Updated: 2023/06/13 00:53:41 by mmezzat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
FN = functions.c
PF = functions_two.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_FN = $(FN:.c=.o)
OBJS_PF = $(PF:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(OBJS_FN) $(OBJS_PF)
	${CC} $(OBJS_SERVER) $(OBJS_FN) $(OBJS_PF) ${CCFLAGS} -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(OBJS_FN) $(OBJS_PF)
	${CC} $(OBJS_CLIENT) $(OBJS_FN) $(OBJS_PF) ${CCFLAGS} -o $(CLIENT)

%.o: %.c minitalk.h
	$(CC) -c $(CCFLAGS) $<

clean:
	rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} ${OBJS_FN} $(OBJS_PF)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
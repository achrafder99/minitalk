# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adardour <adardour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 21:56:22 by adardour          #+#    #+#              #
#    Updated: 2022/12/25 22:16:08 by adardour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 
AR = ar rcs
RM = rm -rf
NAME = minitalk.a
header = minitalk.h

CLIENT_SERVER = client.c server.c
OBJS = ${CLIENT_SERVER:%.c=%.o}

all:${NAME}

%.o:%.c ${header}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS} ${SOURCE}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:clean 
	${RM} ${NAME}

re: fclean all
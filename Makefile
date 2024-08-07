# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 14:23:54 by lopoka            #+#    #+#              #
#    Updated: 2024/08/07 14:37:53 by lopoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_DIR = sources
SRCS = main.c validate.c init.c routine.c strt_thrds.c stop_thrds.c utils.c terminate.c
OBJ = $(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread 

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -o ${NAME} ${CFLAGS} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<

clean :
	rm -f ${OBJ}

fclean :
	rm -f ${NAME} ${OBJ}

re : fclean all

.PHONY: all clean fclean re

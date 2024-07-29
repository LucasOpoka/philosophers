# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 14:23:54 by lopoka            #+#    #+#              #
#    Updated: 2024/07/29 13:49:44 by lopoka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS_DIR = sources
SRCS = main.c validate_av.c init.c strt_thrds.c utils.c rtne_philo.c rtne_monit.c end_all.c
OBJ = $(addprefix $(SRCS_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address,undefined -g 

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

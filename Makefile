# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 20:10:18 by tcynthia          #+#    #+#              #
#    Updated: 2021/05/22 16:44:08 by tcynthia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAKE = make -C

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

RM = rm

SRCS := $(wildcard ./draw/*.c) $(wildcard ./math/*.c) $(wildcard ./parser/*.c) \
		$(wildcard ./gnl/*.c) $(wildcard ./libft/*.c) $(wildcard ./receive/*.c)

OBJ = ${SRCS:.c=.o}

HEADERS = ./list.h ./headers.h ./draw/draw.h ./gnl/get_next_line.h \
		  ./libft/libft.h ./math/math.h ./parser/parser.h ./receive/receive.h

GNLDIR = ./gnl

LIBFTDIR = ./libft

MLXDIR = ./mlx

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -Imlx -c $< -o $@

all: ${NAME} ${HEADERS}

${NAME}: ${OBJ}
	${MAKE} ${GNLDIR} 
	${MAKE} ${LIBFTDIR}
	${MAKE} ${MLXDIR}
	${CC} ${MLXFLAGS} ${OBJ} ./mlx/libmlx.a ./libft/libft.a ./gnl/get_next_line.a -o ${NAME}

${HEADERS}: 
	${CC} ${CFLAGS} -Imlx -c $< -o $@
clean:
	${MAKE} ${LIBFTDIR} clean
	${MAKE} ${GNLDIR} clean
	${MAKE} ${MLXDIR} clean
	${RM} -f ${OBJ}
	${RM} -f screen.bmp

fclean: clean
	${MAKE} ${LIBFTDIR} fclean
	${MAKE} ${GNLDIR} fclean
	${MAKE} ${MLXDIR} fclean
	${RM} -f ${NAME}

re: fclean all

bonus: ${NAME}

.PHONY: all clean fclean re bonus

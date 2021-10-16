

SRCS = get_next_line.c

OBJS = ${SRCS:.c=.o}

NAME = get_next_line.a

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:	${NAME}

re:		fclean all

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

.PHONY: all clean fclean re bonus

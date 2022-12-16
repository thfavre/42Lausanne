CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = push_swap.c pile.c operations.c utils.c sort.c
OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c -I {OBJS} $< -o ${<:.c=.o}


${NAME}:	${OBJS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test

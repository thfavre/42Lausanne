CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ./libft/libft.a
SRCSDIR = ./srcs/
HEADERDIR = ./includes
SRCS = ./srcs/ft_printf.c ./srcs/ft_process.c ./srcs/ft_process_2.c ./srcs/ft_parse.c ./srcs/ft_convert.c
OBJS = ${SRCS:.c=.o}

.c.o:	
	${CC} ${CFLAGS} -c -I ${HEADERDIR} $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			make -C libft
			cp ${LIBFT} .
			mv libft.a libftprintf.a
			ar rcs ${NAME} ${OBJS}
all:	${NAME}
	
test:	${NAME}
	${CC} ${CFLAGS} -o libftprintf main.c -L/. libftprintf.a
	./libftprintf

clean: 
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re: fclean ${NAME}

.PHONY: all fclean clean re test


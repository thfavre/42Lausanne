
NAME 	= bsq

SRC 	= ./error.c ./ft_atoi.c ./ft_str_is_printable.c ./ft_strlen.c ./main.c ./parse.c ./parse_validity.c ./readin.c ./square.c

OBJS	= ${SRCS:.c=.o}

CCAF 	= gcc -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	${OBJS}
			${CCAF} -o ${NAME} ${SRC}
	
all: 		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean .c.o

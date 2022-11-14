NAME 	= libftprintf.a

SRCS 	= 	*/*.c# src/ft_printf.c Libft/*.c
			
OBJS	= ${SRCS:.c=.o}


CC		= gcc
FLAGS 	= # -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	$(OBJS)
			ar rcs $(NAME) $(OBJS)


%.o: %.c
	$(CC) -I. $(FLAGS) -o $@ -c $?
	
all: 		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all


.PHONY:		all clean fclean re .c.o


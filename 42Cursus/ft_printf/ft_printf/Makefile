NAME 	= libftprintf

SRCS 	= 	ft_printf.c ft_putptr_fd.c ft_putunbr_fd.c ft_putxnbr_fd.c # src/ft_printf.c Libft/*.c
			
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


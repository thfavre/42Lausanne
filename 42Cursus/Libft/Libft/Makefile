NAME 	= libft.a

SRCS 	= 	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_memchr.c\
			ft_strncmp.c ft_isalpha.c ft_toupper.c ft_isdigit.c \
			ft_memcpy.c  ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_calloc.c\
			ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_atoi.c\
			ft_memmove.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_memset.c\
			ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c
OBJS	= ${SRCS:.c=.o}



CCAF 	= gcc -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	$(OBJS)
			ar rcs $(NAME) $(OBJS)


#			${CCAF} -o ${NAME} ${SRC}
	
all: 		${NAME}

run:		${OBJS}	
			${CCAF} -o ${NAME} ${SRC}
clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o


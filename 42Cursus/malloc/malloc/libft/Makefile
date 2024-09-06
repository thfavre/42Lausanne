NAME 	= libft.a

SRCS 	= 	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_memchr.c\
			ft_strncmp.c ft_isalpha.c ft_toupper.c ft_isdigit.c \
			ft_memcpy.c  ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_calloc.c\
			ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_atoi.c\
			ft_memmove.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_memset.c\
			ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c\
			
BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS		= $(BONUS:.c=.o)

CC		= gcc
FLAGS 	=  -Wall -Wextra -Werror

RM		= rm -f

${NAME}:	$(OBJS)
			ar rcs $(NAME) $(OBJS)


#			${CCAF} -o ${NAME} ${SRC}
%.o: %.c
	$(CC) -I. $(FLAGS) -o $@ -c $?
	
all: 		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re .c.o


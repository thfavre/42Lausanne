NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
LIBFT_SRCS = $(wildcard src/*.c)
LINKED_LST_SRCS = $(wildcard src/linked_lst/*.c)
PRINTF_SRCS = $(wildcard src/ft_printf/*.c)
GET_NEXT_LINE_SRCS = $(wildcard src/get_next_line/*.c)

OBJS = $(LIBFT_SRCS:.c=.o) $(LINKED_LST_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o) $(GET_NEXT_LINE_SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

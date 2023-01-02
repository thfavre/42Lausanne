SOURCES = server.c client.c client_bonus.c server_bonus.c
OBJECTS = $(SOURCES:.c=.o)
NAME = minitalk

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

${NAME}:	server client


server_bonus: server_bonus.o libft/libft.a
	$(CC) -o $@ $^

client_bonus: client_bonus.o libft/libft.a
	$(CC) -o $@ $^

bonus: server_bonus client_bonus

server: server.o libft/libft.a
	$(CC) -o $@ $^

client: client.o libft/libft.a
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f server client client_bonus server_bonus libft/libft.a

re: fclean all

.PHONY: all bonus clean fclean re


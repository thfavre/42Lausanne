#---Style---#
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

_MOFF		=	\e[?25l
_MON		=	\e[?25h
_MUP		=	\e[1A
_ERASE		=	\e[K

#---Directories Path---#
PATH_SRC =			./srcs/
PATH_OBJS =			./objs/

#---Compilation flags---#
CC = gcc
CFLAGS = #-Wall -Wextra -Werror

# NB_FILES			=	$(shell ls -l $(PATH_SRC) | grep -F .c | wc -l)

NAME = philo

FILES = $(PATH_SRC)main.c		\
		$(PATH_SRC)philo.c		\
		$(PATH_SRC)routine.c	\
		$(PATH_SRC)utils.c		\


OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))



all:	${NAME}

#pr :
#	@printf "\n${_BOLD}${_WHITE}1 ${_YELLOW}2${_END}\n"

${NAME}:	${OBJS}
#	@printf "\n${_BOLD}${_WHITE}Compiling ${_YELLOW}everything${_END}\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "\n${_BOLD}${_GREEN}OK! ${_WHITE}(./${NAME})${_END}\n\n"

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@printf "\t$(_DIM)$(_YELLOW)$(subst $(DIR),,$<)$(_END)\n"

clean:
	@printf "\n${_BOLD}${_WHITE}Removing ${_RED}${NAME}${_WHITE} objects${_END}\n"
	@rm -rf ${PATH_OBJS}

fclean:	clean
	@printf "${_BOLD}${_WHITE}Removing ${_RED}${NAME}${_WHITE} (./${NAME})${_END}\n\n"
	@rm -rf ${NAME}

re: fclean all

.PHONY: all fclean clean re pr

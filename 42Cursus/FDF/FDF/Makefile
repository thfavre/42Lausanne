PATH_SRC =			./src/
PATH_GNL =			$(PATH_SRC)gnl/
PATH_LIBFT =		$(PATH_SRC)Libft/
PATH_GAME =			$(PATH_SRC)game/
PATH_MLX =			./mlx/
PATH_OBJS =			./objs/

MLX = $(PATH_MLX)libmlx.a
LIBFT = $(PATH_LIBFT)libft.a
NAME = fdf

FILES = $(PATH_SRC)main.c $(PATH_GAME)keys.c $(PATH_GAME)update.c $(PATH_GAME)render.c $(PATH_GAME)parse.c $(PATH_GAME)draw.c $(PATH_GAME)vector.c $(PATH_GAME)transform.c $(PATH_GAME)line.c\
		$(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c
OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo objects done!!
	@$(MAKE) -C $(PATH_MLX)
	@$(MAKE) -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)gnl
	@mkdir -p $(PATH_OBJS)game
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make clean -C $(PATH_MLX)
	make clean -C $(PATH_LIBFT)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

.PHONY: re all fclean clean

# Project settings
NAME        = ft_nm
CC          = gcc
CFLAGS      = -Iincludes -I$(LIBFT_DIR)/includes # -Wall -Wextra -Werror
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRCS_DIRS   = src src/elf src/file src/parsing    # Add more directories if needed
OBJS_DIR    = obj

# Colors for output
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RED         = \033[1;31m
BLUE        = \033[1;34m
RESET       = \033[0m

# Automatically detect source and object files
SRCS        = $(wildcard $(addsuffix /*.c, $(SRCS_DIRS)))
OBJS        = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

# Tools
RM          = rm -rf
MAKE        = make

# Default target
all: $(LIBFT) $(NAME)

# Build the final executable
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Build successful!$(RESET)"

# Compile individual object files
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@mkdir -p $(@D)  # Ensure directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Build libft
$(LIBFT):
	@echo "$(BLUE)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Full cleanup
fclean: clean
	@echo "$(RED)Removing $(NAME) and libft...$(RESET)"
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

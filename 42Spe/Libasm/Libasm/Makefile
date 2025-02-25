NAME = libasm.a

SRC = src/ft_strlen.s src/ft_strcpy.s
OBJS_DIR = obj
OBJ = $(SRC:src/%.s=$(OBJS_DIR)/%.o)

NASM_FLAGS = -f elf64

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJS_DIR)/%.o: src/%.s | $(OBJS_DIR)
	nasm $(NASM_FLAGS) $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Target to clean object files
clean:
	rm -f $(OBJ) test.o

# Target to clean both object files and library
fclean: clean
	rm -f $(NAME) test_asm test_c

# Target to recompile everything
re: fclean all

# Compile the test.c file with the libasm.a library
test_c: $(NAME) tests/test.c
	$(CC) $(CFLAGS) -o test_c tests/test.c $(NAME)

# Run the test executable
run_c_test: test_c
	./test_c

# Compile the test.s file with nasm and link it into an executable
test_asm: test.o
	$(CC) -nostartfiles -o test_asm test.o

# Assemble the test.s file using nasm
test.o: tests/test.s
	nasm $(NASM_FLAGS) tests/test.s -o test.o

# Run the test executable
run_asm_test: test_asm
	./test_asm

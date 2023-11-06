# Color codes
COLOR_RESET = \033[0m
COLOR_GREEN = \033[1;32m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[1;31m
COLOR_ORANGE = \033[1;38;5;208m

# Compiler settings
CXX = g++
CXXFLAGS = #-Wall -Wextra -Werror -std=c++98

# Source files
SOURCES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

# Object files
OBJECTS = $(addprefix objs/, $(notdir $(SOURCES:.cpp=.o)))

# Target executable
TARGET = bureau

all: $(TARGET)
	@echo "$(COLOR_GREEN)Compilation completed successfully!$(COLOR_RESET)"

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(COLOR_CYAN)Linking $(TARGET)...$(COLOR_RESET)"

objs/%.o: %.cpp | objs
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(COLOR_YELLOW)Compiling $<...$(COLOR_RESET)"

objs:
	mkdir -p objs

clean:
	rm -rf objs
	@echo "$(COLOR_ORANGE)Object files removed!$(COLOR_RESET)"

fclean: clean
	rm -f $(TARGET)
	@echo "$(COLOR_ORANGE)Executable removed!$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re

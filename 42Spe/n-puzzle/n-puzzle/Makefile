# Specify the source directory
SRC_DIR := src

# Specify the main Python script
MAIN_SCRIPT := src/main.py

# Benchmark script
BENCHMARK_SCRIPT := src/benchmark.py

# Set the name of the Python interpreter
PYTHON := python3

# Default target
.PHONY: all
all: run

# Run all Python scripts
.PHONY: run
run:
	$(PYTHON) $(MAIN_SCRIPT) $(ARGS)

benchmark:
	$(PYTHON) $(BENCHMARK_SCRIPT)

test: benchmark

# Clean up any compiled Python files
.PHONY: clean
clean:
	@echo "Cleaning up..."
	@find $(SRC_DIR) -name '*.pyc' -delete
	@find $(SRC_DIR) -name '__pycache__' -delete

re : clean all

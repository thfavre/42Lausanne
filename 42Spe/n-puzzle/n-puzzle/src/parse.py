import argparse
from typing import List, Tuple

def parseArguments():
	"""
	Parse command-line arguments.

	Returns:
		argparse.Namespace: Parsed arguments.
	"""
	parser = argparse.ArgumentParser(description="N-puzzle solver using A* algorithm")
	parser.add_argument("-s", "--size", type=int, help="Size of the puzzle grid (e.g., 3 for 3x3 puzzle)", default=3)
	parser.add_argument("-f", "--file", type=str, help="Path to input file with initial state of the puzzle, otherwise a random puzzle will be generated")
	parser.add_argument("-c", "--heuristic", type=str, choices=["manhattan", "hamming", "euclidean", "linear_conflict", "manhattan_linear_conflict"], default="manhattan", help="Heuristic function to use")
	parser.add_argument("-t", "--search_strategy", type=str, nargs="+", default=["greedy"], choices=["a_star", "uniform", "greedy"], help="Search strategies to use for solving the puzzle (e.g., a_star, uniform, greedy)")
	parser.add_argument("-r", "--hide-resolution", action="store_false", help="Hide resolution statistics")
	return parser.parse_args()

def parseFile(file: str) -> Tuple[List[int], int]:
	"""
	Parse a file to extract the puzzle grid and size.

	Args:
		file (str): Path to the input file.

	Returns:
		Tuple[List[int], int]: Parsed puzzle grid and size.
	"""
	size = None
	with open(file, "r") as f:
		lines = f.readlines()

	# Find the size
	for i, line in enumerate(lines):
		splited_line = line.split()
		if not splited_line or splited_line[0].startswith("#"):
			continue
		# Check if the first non-comment line contains the size of the puzzle
		if not splited_line[0].isdigit() or (len(splited_line) > 1 and not splited_line[1].startswith("#")):
			raise ValueError("The first non-comment line should contain the size of the puzzle")
		size = int(splited_line[0])
		break

	lines = lines[i + 1:]
	# Create the grid
	grid = []
	for line in lines:
		splited_line = line.split()
		if not splited_line or splited_line[0].startswith("#"):
			continue
		for elem in splited_line:
			if elem.startswith("#"):
				break
			if not elem.isdigit():
				raise ValueError(f"Invalid element in the grid: {elem}")
			if int(elem) < 0 or int(elem) >= size * size:
				raise ValueError(f"Invalid element value in the grid: {elem}")
			if int(elem) in grid:
				raise ValueError(f"Duplicate element in the grid: {elem}")
			grid.append(int(elem))
		if len(grid) > size * size:
			raise ValueError("Too many elements in the grid")
		if len(grid) % size != 0:
			raise ValueError(f"Invalid number of elements in a row {splited_line}")
	if len(grid) != size * size:
		raise ValueError("Invalid number of elements in the grid")
	return grid, size

# - Critucal Optimization : not make a move that will put the puzzle in a previous state
# - Heuristics : choose a move that reduce the time complexity

# Manhattan Priority Function : (Find the best solution out of all)

from npuzzle_gen import make_puzzle
from solve import solvePuzzle
from parse import parseFile, parseArguments
from time import sleep

def main():
	try:
		args = parseArguments()
		size = args.size
		if size < 3:
			raise ValueError("Minimum size of the puzzle is 3")
		heuristic = args.heuristic
		searchStrategies = args.search_strategy
		if args.file:
			grid, size = parseFile(args.file)
			print("Grid from file:")
		else:
			grid = make_puzzle(size, True, 1000)
			print("Random grid:")
		for i in range(size):
			print(" ".join(str(x).rjust(len(str(size*size))) for x in grid[i*size:(i+1)*size]))
		print(f"\nWill solve the puzzle with the {heuristic} heuristic using the {' and '.join(searchStrategies)} {'strategy' if len(searchStrategies) == 0 else 'strategies'}...\n")
		solvePuzzle(grid, size, heuristic, searchStrategies, showStats=True, show_resolution=args.hide_resolution)
	except Exception as e:
		print(f"Error: {e}")


if __name__ == "__main__":
	main()

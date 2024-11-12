from AStar import AStar
from npuzzle_gen import make_puzzle

def benchmark() -> None:
	averageTime: float
	averageNbMoves: float
	nbTest: int = 5
	heuristics: tuple[str] = ("manhattan", "euclidean", "linear_conflict", "manhattan_linear_conflict", "hamming")
	searchStrategy = "greedy" # a_star, uniform or greedy
	# heuristic : str = "manhattan"

	print(f"Starting benchmark with {', '.join(heuristics)}... ({nbTest} tests)")

	size: int = 3
	while True:
		print(f"\nSize: {size}")
		for heuristic in heuristics:
			totalTime: float = 0.0
			totalNbMoves: float = 0.0
			for i in range(nbTest):
				print(f"\t-{heuristic}\t {i+1}/{nbTest}", end="\r")  # i+1 for more natural counting display
				grid = make_puzzle(size, True, 1000)
				solver: AStar = AStar(grid, size, showProgress=False, heuristic=heuristic, searchStrategy=searchStrategy)
				elapsedTime = solver.getSolutionElapsedTime()
				nbMoves = solver.getSolutionNbMoves()

				# Check for None before adding to totals
				if elapsedTime is not None:
					totalTime += elapsedTime
				if nbMoves is not None:
					totalNbMoves += nbMoves

			averageTime = totalTime / nbTest
			averageNbMoves = totalNbMoves / nbTest

			print('\r' + ' ' * 80, end='\r')  # erase the "loading" stats
			print(f"\t-{heuristic:<23}\t Average time [s]: {averageTime:.5f}\t Average moves: {averageNbMoves:.1f}")
		size += 1
if __name__ == "__main__":
	benchmark()

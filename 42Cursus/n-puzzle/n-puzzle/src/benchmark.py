from AStar import AStar
from npuzzle_gen import make_puzzle

def benchmark() -> None:
	averageTime: float
	averageNbMoves: float
	nbTest: int = 10
	heuristics: tuple[str] = ("manhattan", "euclidean", "hamming", "linear_conflict") #"custom"
	# heuristic : str = "manhattan"

	print(f"Starting benchmark with {", ".join(heuristics)}... ({nbTest} tests for size 3 to 10)")

	for size in range(3, 11):
		print(f"\nSize: {size}")
		for heuristic in heuristics:
			totalTime: float = 0.0
			totalNbMoves: float = 0.0
			for i in range(nbTest):
				print(f"\t-{heuristic}\t {i+1}/{nbTest}", end="\r")  # i+1 for more natural counting display
				grid = make_puzzle(size, True, 1000)
				solver: AStar = AStar(grid, size, showProgress=False, heuristic=heuristic)
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
			print(f"\t-{heuristic:<20}\t Average time [s]: {averageTime:.5f}\t Average moves: {averageNbMoves:.1f}")
if __name__ == "__main__":
	benchmark()

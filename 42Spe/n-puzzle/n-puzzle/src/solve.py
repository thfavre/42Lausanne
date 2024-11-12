from time import sleep
from typing import List
from AStar import AStar

def solvePuzzle(grid: List[int], size: int, heuristic: str, searchStrategies: str, showStats: bool = True, show_resolution: bool = True) -> None:
    """
    Solve the puzzle using the A* algorithm and print the solution.

    Args:
        grid (List[int]): Initial puzzle grid.
        size (int): Size of the puzzle grid.
        heuristic (str): Heuristic function to use.
        searchStrategy (str): The search strategy to use ('a_star', 'uniform', 'greedy').
        showStats (bool): Whether to show solving statistics.
        show_resolution (bool): Whether to show the step-by-step resolution.
    """
    for searchStrategy in searchStrategies:
        solver = AStar(grid, size, heuristic, searchStrategy=searchStrategy, showProgress=showStats)
        if solver.isSolved():
            print("\nSolution Found!")
            if show_resolution:
                print("\nSequence of states:")
                steps = solver.getSteps()
                for step in steps:
                    print(f"Move {step.getLevel()}:")
                    step.showGrid()
                    print()
                    sleep(1 / len(steps))
            print(f"{size}x{size} puzzle solved with the '{heuristic}' heuristic heuristic using '{searchStrategy}' strategy::")
            print(f"\t-Elapsed time: {solver.getSolutionElapsedTime():.7f} seconds")
            print(f"\t-Number of moves required: {solver.getSolutionNbMoves()}")
            print(f"\t-Total number of states visited: {solver.getNumberVisited()}")
            print(f"\t-Maximum queue size during search: {solver.getMaxQueueSize()}")
        else:
            print("\nNo solution found...")
        if searchStrategy != searchStrategies[-1]:
            print("\n" + "-" * 10, end="\n\n")

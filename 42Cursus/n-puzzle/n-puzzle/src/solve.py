from time import sleep
from typing import List
from AStar import AStar

def solvePuzzle(grid: List[int], size: int, heuristic: str, show_stats: bool = True, show_resolution: bool = True) -> None:
    """
    Solve the puzzle using the A* algorithm and print the solution.

    Args:
        grid (List[int]): Initial puzzle grid.
        size (int): Size of the puzzle grid.
        heuristic (str): Heuristic function to use.
        show_stats (bool): Whether to show solving statistics.
        show_resolution (bool): Whether to show the step-by-step resolution.
    """
    solver = AStar(grid, size, heuristic, show_stats)
    if solver.isSolved():
        print("\nSolution Found:")
        print("\nSequence of states:")
        if show_resolution:
            steps = solver.getSteps()
            for step in steps:
                print(f"Move {step.getLevel()}:")
                step.showGrid()
                print()
                sleep(1 / len(steps))
        print(f"{size}x{size} puzzle solved with the {heuristic} heuristic:")
        print(f"\t-Elapsed time: {solver.getSolutionElapsedTime():.7f} seconds")
        print(f"\t-Number of moves required: {solver.getSolutionNbMoves()}")
        print(f"\t-Total number of states visited: {solver.getNumberVisited()}")
        print(f"\t-Maximum queue size during search: {solver.getMaxQueueSize()}")
    else:
        print("\nNo solution found...")

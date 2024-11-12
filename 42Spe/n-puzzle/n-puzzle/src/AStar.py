import time
from node import Node
from priority_queue import PriorityQueue
from npuzzle_gen import make_goal
from typing import List, Optional, Set, Tuple

CLEAR_LINE = '\r' + ' ' * 80 + '\r'
STATS_INTERVAL = 200

class AStar:
	def __init__(self, grid: List[int], size: int, heuristic: str = "manhattan", searchStrategy: str = 'greedy', showProgress: bool = True) -> None:
		"""
		Initialize the A* solver for the given puzzle grid.

		Args:
			grid (List[int]): Initial puzzle grid.
			size (int): Size of the puzzle grid.
			heuristic (str): Heuristic function to use.
            searchStrategy (str): The type of search algorithm ('a_star', 'uniform', 'greedy').
			showInfos (bool): Whether to print detailed information during solving.
		"""
		self._heuristic: str = heuristic
		self._solutionGrid: List[int] = make_goal(size)
		self._showProgress: bool = showProgress
		self._isSolved: bool = False
		self._steps: Optional[List[Node]] = None
		self._numberVisited: int = 0
		self._maxQueueSize: int = 0
		self._nbMovesRequired: Optional[int] = None
		self._elapsedTime: Optional[float] = None
		self._searchType: str = searchStrategy

		if not self._isSolvable(grid, size):
			print("\nThis puzzle is not solvable.")
			return

		startNode: Node = Node(None, grid, self._solutionGrid, size, self._heuristic, searchStrategy=self._searchType)
		self._isSolved: bool = self._solve(startNode, size)
		if not self._isSolved:
			raise Exception("This puzzle should be solvable but no solution was found...!")


	def _countInversion(self, grid: List[int]) -> bool:
		"""
		Count the number of inversions in the puzzle grid.

		Args:
			grid (List[int]): Initial puzzle grid.

		Returns:
			bool: True if the puzzle is solvable, False otherwise.
		"""
		invCount: int = 0
		for i in range(len(grid)):
			if grid[i] == 0:
				continue
			for j in range(i + 1, len(grid)):
				if grid[j] == 0:
					continue
				if grid[i] > grid[j]:
					invCount += 1
		return invCount

	def _isSolvable(self, grid: List[int], size: int) -> bool:
		"""
		Check if the puzzle is solvable.

		Args:
			grid (List[int]): Initial puzzle grid.

		Returns:
			bool: True if the puzzle is solvable, False otherwise.
		"""
		invCount: int = self._countInversion(grid)
		solutionInvCount: int = self._countInversion(self._solutionGrid)
		if size % 2 == 0:
			invCount += grid.index(0)
			solutionInvCount += self._solutionGrid.index(0)
		return invCount % 2 == solutionInvCount % 2

	def _solve(self, startNode: Node, size: int) -> None:
		"""
		Solve the puzzle using the A* algorithm.

		Args:
			startNode (Node): The starting node.
			size (int): Size of the puzzle grid.
		"""
		startTime: float = time.time()
		priorityQueue: PriorityQueue = PriorityQueue()
		priorityQueue.push(startNode)
		seenGrid: Set[Tuple[int, ...]] = set()

		while not priorityQueue.isEmpty():
			minimalNode: Node = priorityQueue.pop()
			self._numberVisited += 1
			seenGrid.add(tuple(minimalNode.getGrid()))
			self._maxQueueSize = max(self._maxQueueSize, len(priorityQueue))

			# Check if the current node is the solution
			if minimalNode.getGrid() == self._solutionGrid:
				self._elapsedTime = time.time() - startTime
				self._nbMovesRequired = minimalNode.getLevel()
				self._steps = AStar._getSteps(minimalNode)
				return True

			for child in minimalNode.createChildrenNodes(self._solutionGrid, size):
				if tuple(child.getGrid()) not in seenGrid:
					priorityQueue.push(child)

			if self._showProgress and (self._numberVisited < 10 or self._numberVisited % STATS_INTERVAL == 0):
				print(f"Number of visited states: {self._numberVisited:<7}\t Elapsed time: {(time.time()-startTime):.3f}s", end="\r")
		return False

	def _clearConsole(self) -> None:
		"""Clear the current console line."""
		print(CLEAR_LINE, end='')

	@staticmethod
	def _getSteps(endNode: Node) -> List[Node]:
		"""
		Retrieve the steps from the initial node to the solution.

		Args:
			endNode (Node): The final node in the solution path.

		Returns:
			List[Node]: List of nodes representing the steps.
		"""
		moves: List[Node] = []
		while endNode:
			moves.append(endNode)
			endNode = endNode.getParentNode()
		return moves[::-1]

	# Public getters for AStar class
	def getSolutionGrid(self) -> List[int]:
		"""Get the goal grid."""
		return self._solutionGrid

	def isSolved(self) -> bool:
		"""Check if the puzzle is solved."""
		return self._isSolved

	def getSteps(self) -> Optional[List[Node]]:
		"""Get the steps to solve the puzzle."""
		return self._steps

	def getNumberVisited(self) -> int:
		"""Get the number of visited nodes."""
		return self._numberVisited

	def getMaxQueueSize(self) -> int:
		"""Get the maximum size of the queue."""
		return self._maxQueueSize

	def getSolutionNbMoves(self) -> Optional[int]:
		"""Get the number of moves required to solve the puzzle."""
		return self._nbMovesRequired

	def getSolutionElapsedTime(self) -> Optional[float]:
		"""Get the time elapsed to solve the puzzle."""
		return self._elapsedTime

	def getHeuristic(self) -> str:
		"""Get the heuristic function used."""
		return self._heuristic


if __name__ == "__main__":
	from npuzzle_gen import make_puzzle
	from time import sleep

	heuristic: str ="manhattan"
	print(f"Will solve a puzzle from size 3 to 10 with the {heuristic} heuristic...")
	sleep(1)
	for size in range(3, 11):
		print(f"\n**** SIZE {size} ****")
		AStar(make_puzzle(size, True, 1000), size, heuristic=heuristic, showProgress=True)

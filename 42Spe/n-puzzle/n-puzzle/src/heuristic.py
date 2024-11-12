from typing import List, Tuple
from functools import lru_cache

class Node:
	@staticmethod
	@lru_cache(None)
	def getCoordinates(index: int, size: int) -> Tuple[int, int]: return index % size, index // size


class Heuristic:
	@staticmethod
	def manhattanDistanceForTile(currentIndex: int, element: int, solution: List[int], size: int) -> int:
		"""
		Calculate the Manhattan distance for a single tile.

		Args:
			currentIndex (int): The current index of the tile in the grid.
			element (int): The value of the tile.
			solution (List[int]): The goal state of the puzzle.
			size (int): Size of the puzzle grid.

		Returns:
			int: Manhattan distance for this tile.
		"""
		if element == 0:
			return 0

		currentX, currentY = Node.getCoordinates(currentIndex, size)
		goalIndex = solution.index(element)
		goalX, goalY = Node.getCoordinates(goalIndex, size)

		return abs(currentX - goalX) + abs(currentY - goalY)

	@staticmethod
	def euclideanDistanceForTile(currentIndex: int, element: int, solution: List[int], size: int) -> float:
		"""
		Calculate the Euclidean distance for a single tile.

		Args:
			currentIndex (int): The current index of the tile in the grid.
			element (int): The value of the tile.
			solution (List[int]): The goal state of the puzzle.
			size (int): Size of the puzzle grid.

		Returns:
			float: Euclidean distance for this tile.
		"""
		if element == 0:
			return 0.0

		currentX, currentY = Node.getCoordinates(currentIndex, size)
		goalIndex = solution.index(element)
		goalX, goalY = Node.getCoordinates(goalIndex, size)

		return ((currentX - goalX) ** 2 + (currentY - goalY) ** 2) ** 0.5

	@staticmethod
	def linearConflictInLine(line: List[int], goalLine: List[int]) -> int:
		"""
		Calculate linear conflicts in a row or column.

		Args:
			line (List[int]): The current row or column of tiles.
			goalLine (List[int]): The goal state of the corresponding row or column.

		Returns:
			int: The number of linear conflicts.
		"""
		conflictCount = 0
		for i in range(len(line)):
			if line[i] == 0 or line[i] not in goalLine:
				continue
			for j in range(i + 1, len(line)):
				if line[j] == 0 or line[j] not in goalLine:
					continue
				if goalLine.index(line[i]) > goalLine.index(line[j]):
					conflictCount += 1
		return conflictCount

	@staticmethod
	def manhattan(node: Node, solution: List[int], size: int) -> int:
		"""
		Calculate the Manhattan distance heuristic for the N-puzzle.
		The Manhattan distance is the sum of the distances of each tile
		to its goal position, moving only in horizontal or vertical directions.

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for a 3x3 puzzle).

		Returns:
			int: Total Manhattan distance for the current grid configuration.
		"""
		grid = node.getGrid()
		return sum(Heuristic.manhattanDistanceForTile(i, el, solution, size) for i, el in enumerate(grid))

	@staticmethod
	def hamming(node: Node, solution: List[int]) -> int:
		"""
		Calculate the Hamming distance heuristic for the N-puzzle.
		The Hamming distance is the number of tiles that are not in their goal positions.

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.

		Returns:
			int: Hamming distance for the current grid configuration.
		"""
		grid = node.getGrid()
		return sum(1 for i, el in enumerate(grid) if el != 0 and el != solution[i])

	@staticmethod
	def euclidean(node: Node, solution: List[int], size: int) -> float:
		"""
		Calculate the Euclidean distance heuristic for the N-puzzle.
		The Euclidean distance is the sum of the straight-line distances of each tile
		from its current position to its goal position.

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for a 3x3 puzzle).

		Returns:
			float: Total Euclidean distance for the current grid configuration.
		"""
		grid = node.getGrid()
		return sum(Heuristic.euclideanDistanceForTile(i, el, solution, size) for i, el in enumerate(grid))

	@staticmethod
	def linearConflict(node: Node, solution: List[int], size: int) -> int:
		"""
		Calculate the linear conflict heuristic for the N-puzzle.
		A linear conflict occurs when two tiles are in their goal row or column,
		but are reversed relative to their goal positions. Resolving a linear
		conflict requires at least one additional move.

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for a 3x3 puzzle).

		Returns:
			int: Linear conflict value for the current grid configuration.
		"""
		grid = node.getGrid()
		conflictCount = 0

		# Check rows for linear conflicts
		for row in range(size):
			currentRow = [grid[row * size + i] for i in range(size)]
			goalRow = [solution[row * size + i] for i in range(size)]
			conflictCount += Heuristic.linearConflictInLine(currentRow, goalRow)

		# Check columns for linear conflicts
		for col in range(size):
			currentCol = [grid[col + size * i] for i in range(size)]
			goalCol = [solution[col + size * i] for i in range(size)]
			conflictCount += Heuristic.linearConflictInLine(currentCol, goalCol)

		return 2 * conflictCount  # Each conflict requires at least two moves to resolve

	@staticmethod
	def manhattanPlusLinearConflict(node: Node, solution: List[int], size: int) -> int:
		"""
		Calculate the heuristic by combining Manhattan distance
		with linear conflict.

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for 3x3 puzzle).

		Returns:
			int: Custom heuristic value.
		"""
		manhattanDistance = Heuristic.manhattan(node, solution, size)
		linearConflict = Heuristic.linearConflict(node, solution, size)

		return manhattanDistance + linearConflict
		grid = node.getGrid()


	@staticmethod
	def evaluate(node: Node, solution: List[int], size: int, heuristic_type: str) -> int:
		"""
		Evaluate the given heuristic for a node.

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for 3x3 puzzle).
			heuristic_type (str): Type of heuristic to use.

		Returns:
			int: Heuristic value.
		"""
		if heuristic_type == "manhattan":
			return Heuristic.manhattan(node, solution, size) # + node.getLevel()
		elif heuristic_type == "hamming":
			return Heuristic.hamming(node, solution)
		elif heuristic_type == "linear_conflict":
			return Heuristic.linearConflict(node, solution, size) + Heuristic.manhattan(node, solution, size) # + node.getLevel()
		elif heuristic_type == "euclidean":
			return Heuristic.euclidean(node, solution, size)
		elif heuristic_type == "manhattan_linear_conflict":
			return Heuristic.manhattanPlusLinearConflict(node, solution, size)
		else:
			raise ValueError(f"Unsupported heuristic type: {heuristic_type}")

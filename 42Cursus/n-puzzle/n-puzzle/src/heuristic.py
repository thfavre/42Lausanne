from typing import List, Tuple
class Node: pass

class Heuristic:
	@staticmethod
	def manhattan(node: Node, solution: List[int], size: int) -> int:
		"""
		Calculate the Manhattan distance heuristic for the N-puzzle.
		(sum of the distances of each tile to its goal position)

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for 3x3 puzzle).

		Returns:
			int: Manhattan distance heuristic value.
		"""
		grid = node.getGrid()
		total = 0
		for i, el in enumerate(grid):
			if el == 0:
				continue
			xGrid = i % size
			yGrid = i // size
			xSolution = solution.index(el) % size
			ySolution = solution.index(el) // size
			total += abs(xGrid - xSolution) + abs(yGrid - ySolution)
		return total

	@staticmethod
	def hamming(node: Node, solution: List[int]) -> int:
		"""
		Calculate the Hamming distance heuristic for the N-puzzle.
		(number of misplaced tiles)

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.

		Returns:
			int: Hamming distance heuristic value.
		"""
		grid = node.getGrid()
		total = 0
		for i, el in enumerate(grid):
			if el == 0:
				continue
			if el != solution[i]:
				total += 1
		return total

	@staticmethod
	def euclidean(node: Node, solution: List[int], size: int) -> int:
		"""
		Calculate the Euclidean distance heuristic for the N-puzzle.
		(distance between each tile and its goal position)

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for 3x3 puzzle).

		Returns:
			int: Euclidean distance heuristic value.
		"""
		grid = node.getGrid()
		total = 0
		for i, el in enumerate(grid):
			if el == 0:
				continue
			xGrid = i % size
			yGrid = i // size
			xSolution = solution.index(el) % size
			ySolution = solution.index(el) // size
			total += ((xGrid - xSolution) ** 2 + (yGrid - ySolution) ** 2) ** 0.5
		return total

	@staticmethod
	def linearConflict(node: Node, solution: List[int], size: int) -> int:
		"""
		Calculate the linear conflict heuristic for the N-puzzle.
		(number of conflicts in each row and column)

		Args:
			node (Node): Current node in the puzzle.
			solution (List[int]): Goal state of the puzzle.
			size (int): Size of the puzzle grid (e.g., 3 for 3x3 puzzle).

		Returns:
			int: Linear conflict heuristic value.
		"""
		grid = node.getGrid()
		conflict_count = 0

		for i in range(size):
			# Check conflicts in rows
			row_conflicts = 0
			col_conflicts = 0

			for j in range(size):
				current_row_goal = solution[i * size + j]
				current_col_goal = solution[j * size + i]

				if grid[i * size + j] != 0 and grid[i * size + j] != current_row_goal:
					for k in range(j + 1, size):
						next_row_goal = solution[i * size + k]
						if (grid[i * size + k] != 0 and
								grid[i * size + k] != next_row_goal and
								current_row_goal > next_row_goal):
							row_conflicts += 1

				if grid[j * size + i] != 0 and grid[j * size + i] != current_col_goal:
					for k in range(j + 1, size):
						next_col_goal = solution[k * size + i]
						if (grid[k * size + i] != 0 and
								grid[k * size + i] != next_col_goal and
								current_col_goal > next_col_goal):
							col_conflicts += 1

			conflict_count += row_conflicts + col_conflicts

		return 2 * conflict_count

	@staticmethod
	def custom(node: Node, solution: List[int], size: int) -> int:
		# TODO!
		return node.getLevel() # uniform cost search


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
		elif heuristic_type == "custom":
			return Heuristic.custom(node, solution, size)
		else:
			raise ValueError(f"Unsupported heuristic type: {heuristic_type}")

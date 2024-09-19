from heuristic import Heuristic
from typing import List, Optional

# ! TODO add the comments
class Node:
    def __init__(self, parentNode: Optional['Node'], grid: List[int], solutionGrid: List[int], gridSize: int, heuristic: str) -> None:
        self._parentNode: Optional['Node'] = parentNode
        self._grid: List[int] = grid
        self._gridSize: int = gridSize
        self._heuristic: str = heuristic
        self._level: int = 0 if not parentNode else parentNode.getLevel() + 1

        self._cost: int = Heuristic.evaluate(self, solutionGrid, gridSize, self._heuristic)

    # def _manhattanHeuristic(self, grid: List[int], solution: List[int], size: int) -> int:
    #     total: int = 0
    #     for i, el in enumerate(grid):
    #         if el == 0:
    #             continue
    #         xGrid: int = i % size
    #         yGrid: int = i // size
    #         xSolution: int = solution.index(el) % size
    #         ySolution: int = solution.index(el) // size
    #         total += abs(xGrid - xSolution) + abs(yGrid - ySolution)
    #     return total

    def showGrid(self) -> None:
        w: int = len(str(self._gridSize * self._gridSize)) + 1
        for i, nb in enumerate(self._grid):
            print(str(nb).rjust(w), end="")
            if ((i + 1) % self._gridSize == 0):
                print()

    def __lt__(self, other: 'Node') -> bool:
        return self._cost < other._cost

    def createChildrenNodes(self, solutionGrid: List[int], gridSize: int) -> List['Node']:
        newNodes: List['Node'] = []
        zeroX: int = self._grid.index(0) % gridSize
        zeroY: int = self._grid.index(0) // gridSize

        # Move the 0 to the right
        if zeroX < gridSize - 1:
            newGrid: List[int] = self._grid.copy()
            newGrid[zeroY * gridSize + zeroX], newGrid[zeroY * gridSize + zeroX + 1] = \
                newGrid[zeroY * gridSize + zeroX + 1], newGrid[zeroY * gridSize + zeroX]
            newNodes.append(Node(self, newGrid, solutionGrid, gridSize, self._heuristic))

        # Move the 0 to the left
        if zeroX > 0:
            newGrid = self._grid.copy()
            newGrid[zeroY * gridSize + zeroX], newGrid[zeroY * gridSize + zeroX - 1] = \
                newGrid[zeroY * gridSize + zeroX - 1], newGrid[zeroY * gridSize + zeroX]
            newNodes.append(Node(self, newGrid, solutionGrid, gridSize, self._heuristic))

        # Move the 0 to the bottom
        if zeroY < gridSize - 1:
            newGrid = self._grid.copy()
            newGrid[zeroY * gridSize + zeroX], newGrid[zeroY * gridSize + zeroX + gridSize] = \
                newGrid[zeroY * gridSize + zeroX + gridSize], newGrid[zeroY * gridSize + zeroX]
            newNodes.append(Node(self, newGrid, solutionGrid, gridSize, self._heuristic))

        # Move the 0 to the top
        if zeroY > 0:
            newGrid = self._grid.copy()
            newGrid[zeroY * gridSize + zeroX], newGrid[zeroY * gridSize + zeroX - gridSize] = \
                newGrid[zeroY * gridSize + zeroX - gridSize], newGrid[zeroY * gridSize + zeroX]
            newNodes.append(Node(self, newGrid, solutionGrid, gridSize, self._heuristic))

        return newNodes

    # Getters
    def getParentNode(self) -> Optional['Node']:
        return self._parentNode

    def getGrid(self) -> List[int]:
        return self._grid

    def getGridSize(self) -> int:
        return self._gridSize

    def getLevel(self) -> int:
        return self._level

    def getCost(self) -> int:
        return self._cost

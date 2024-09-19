from heapq import heappush, heappop
from typing import Any, List

class PriorityQueue:
	def __init__(self) -> None:
		self._heap: List[Any] = []

	def push(self, element: Any) -> None:
		heappush(self._heap, element)

	def pop(self) -> Any:
		return heappop(self._heap)

	def isEmpty(self) -> bool:
		return len(self._heap) == 0

	def __len__(self) -> int:
		return len(self._heap)

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

class Train:
	def __init__(self) -> None:
		data = Train._load_data('./data.csv')
		data = Train._normalize_data(data)

		self._mse_threshold = 0.00001 # Mean Squared Error
		self._max_iterations = 1111
		self._current_iteration = 0
		self._learning_rate = 0.05

		self._eq_intercept, self._eq_slope = 0, 0

		self._gradient_descent(data)
		# self.plot(data)

	@staticmethod
	def _load_data(path: str) -> tuple[tuple[int, int]]:
		"""Load the data from the given file path."""
		data = []
		with open(path, 'r') as file:
			next(file)  # Skip the first line (header)
			for line in file:
				numbers = line.strip().split(',')
				if len(numbers) != 2:
					raise ValueError(f"The line: '{line.strip()}' is not formatted correctly.")
				try:
					data.append((int(numbers[0]), int(numbers[1])))
				except ValueError:
					raise ValueError(f"Unable to convert the values in line: '{line.strip()}' to integers.")
		return tuple(data)

	@staticmethod
	def _normalize_data(data: tuple[tuple[int, int]]) -> tuple[tuple[int, int]]:
		"""Normalize the data to be between 0 and 1."""
		minimum_x = min(data, key=lambda x: x[0])[0]
		maximum_x = max(data, key=lambda x: x[0])[0]
		minimum_y = min(data, key=lambda x: x[1])[1]
		maximum_y = max(data, key=lambda x: x[1])[1]
		return tuple(((x - minimum_x) / (maximum_x - minimum_x), (y - minimum_y) / (maximum_y - minimum_y)) for x, y in data)

	def _gradient_descent(self, data):
		"""Perform the gradient descent algorithm on the given data."""
		fig, ax = plt.subplots()
		ax.plot(*zip(*data), 'ro')
		# ax.plot(data, 'ro')
		previous_mse = None
		delta_mse = None

		while not self._stop_condition(delta_mse):

			data_len = len(data)
			tmp_eq_intercept = self._learning_rate * 1/data_len * sum(self._estimate_y(data[i][0]) - data[i][1] for i in range(data_len))
			tmp_eq_slope = self._learning_rate * 1/data_len * sum((self._estimate_y(data[i][0]) - data[i][1])* data[i][0] for i in range(data_len))
			self._eq_intercept -= tmp_eq_intercept
			self._eq_slope -= tmp_eq_slope

			mse = self._mean_squared_error(data)
			delta_mse = previous_mse - mse if previous_mse is not None else None
			previous_mse = mse

			# plt.clf()
			self._current_iteration += 1

			x = [i/100 for i in range(0, 100, 1)]
			y = [self._estimate_y(i) for i in x]
			plt.plot(x, y)
			plt.pause(0.05)

		plt.show()

	def _estimate_y(self, x: float) -> float:
		return self._eq_slope * x + self._eq_intercept

	def _stop_condition(self, delta_mse: float | None) -> bool:
		"""Check if the stopping condition is met."""
		if delta_mse is not None and delta_mse < self._mse_threshold:
			return True
		if self._current_iteration >= self._max_iterations:
			return True
		return False

	def _mean_squared_error(self, data: tuple[tuple[int, int]]) -> float:
		"""Compute the mean squared error of the model on the given data."""
		return sum((self._estimate_y(x) - y) ** 2 for x, y in data) / len(data)

	def plot(self, data):
		plt.plot(*zip(*data), 'ro')

		x = [i/100 for i in range(0, 100, 1)]
		y = [self._estimate_y(i) for i in x]
		plt.plot(x, y)
		plt.show()


if __name__ == "__main__":
	t = Train()

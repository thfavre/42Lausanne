import matplotlib.pyplot as plt
from matplotlib import style

class Train:
	def __init__(self, data_path, x_label: str='X', y_label: str='Y', plot: bool=True,
			  outputFile: str|None=None, mse_threshold: float=0.00000001,
			  max_iterations: int=100000, learning_rate: float=0.05 ) -> None:
		original_data = Train._load_data(data_path)
		normalized_data = Train._normalize_data(original_data)
		self._x_label = x_label
		self._y_label = y_label

		self._mse_threshold = mse_threshold # Mean Squared Error
		self._max_iterations = max_iterations
		self._learning_rate = learning_rate
		self._current_iteration = 0

		self._eq_intercept, self._eq_slope = 0, 0

		self._gradient_descent(normalized_data)
		self._denorm_intercept, self._denorm_slope = self._denormalize_equation(original_data)
		print(f"Final regression equation: y = {round(self._eq_intercept, 4)} + {round(self._eq_slope, 4)} * x")
		print(f"Denormalized regression equation: y = {round(self._denorm_intercept, 4)} + {round(self._denorm_slope, 4)} * x")
		print(f"Mean Squared Error: {round(self._mean_squared_error(normalized_data), 10)}")
		print(f"Number of iterations: {self._current_iteration}")
		if outputFile:
			self._save_to_file(outputFile)
		if plot:
			self._plot(original_data, normalized_data)

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
					data.append((int(numbers[0]), int(numbers[1]))) # TODO ? put float?
				except ValueError:
					raise ValueError(f"Unable to convert the values in line: '{line.strip()}' to integers.")
		return tuple(data)

	@staticmethod
	def _normalize_data(data: tuple[tuple[int, int]]) -> tuple[tuple[float, float]]:
		"""Normalize the data to be between 0 and 1."""
		minimum_x = min(data, key=lambda x: x[0])[0]
		maximum_x = max(data, key=lambda x: x[0])[0]
		minimum_y = min(data, key=lambda x: x[1])[1]
		maximum_y = max(data, key=lambda x: x[1])[1]
		return tuple(((x - minimum_x) / (maximum_x - minimum_x), (y - minimum_y) / (maximum_y - minimum_y)) for x, y in data)

	def _gradient_descent(self, data):
		"""Perform the gradient descent algorithm on the given data."""
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

			self._current_iteration += 1

	def _estimate_y(self, x: float) -> float:
		return self._eq_slope * x + self._eq_intercept

	def _denormalize_element(self, element: float, list: tuple[float]) -> float:
		"""Denormalize the given element using the given list."""
		minimum = min(list)
		maximum = max(list)
		return element * (maximum - minimum) + minimum

	def _denormalize_equation(self, original_data):
		"""Denormalize the slope and intercept using the _denormalize_element function."""
		all_original_x, all_original_y = zip(*original_data)
		denorm_slope = self._denormalize_element(self._eq_slope, all_original_y) / self._denormalize_element(1, all_original_x)
		denorm_intercept = self._denormalize_element(self._eq_intercept, all_original_y)# - denorm_slope * min(all_original_x)
		return denorm_intercept, denorm_slope

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

	def _save_to_file(self, output_file):
		"""Save the output to the given file."""
		print(f"Saving the output to '{output_file}'")
		with open(output_file, 'w') as file:
			file.write(f"{self._eq_intercept},{self._eq_slope}")

	def _plot(self, original_data, normalized_data):
		style.use('seaborn-v0_8-pastel')
		plt.figure(figsize=(12, 6))  # Create a figure with two subplots

		# Plot the original data
		plt.subplot(1, 2, 1)  # 1 row, 2 columns, 1st subplot
		all_original_x, all_original_y = zip(*original_data)
		plt.plot(all_original_x, all_original_y, 'go', label='Original Data Points')
		# Draw the regression line for original data (denormalized)
		x_min = self._eq_intercept
		x_max = self._eq_intercept + self._eq_slope
		plt.plot([self._denormalize_element(0, all_original_x), self._denormalize_element(1, all_original_x)], [self._denormalize_element(x_min, all_original_y), self._denormalize_element(x_max, all_original_y)], label='Regression Line')

		plt.xlabel(self._x_label)
		plt.ylabel(self._y_label)
		plt.title('Original Data')
		plt.legend()

		# Plot the normalized data
		plt.subplot(1, 2, 2)  # 1 row, 2 columns, 2nd subplot
		all_x_norm, all_y_norm = zip(*normalized_data)
		plt.plot(all_x_norm, all_y_norm, 'bo', label='Normalized Data Points')
		# Draw the regression line for normalized data
		plt.plot([0, 1], [self._eq_intercept, self._eq_intercept + self._eq_slope], label='Regression Line')
		plt.xlabel('Normalized ' + self._x_label)
		plt.ylabel('Normalized ' + self._y_label)
		plt.title('Normalized Data')
		plt.legend()

		plt.tight_layout()  # Adjust layout so subplots fit well together

		plt.show()


def main():
	import argparse

	parser = argparse.ArgumentParser(description='Train a linear regression model on the given data.',
								  formatter_class=argparse.ArgumentDefaultsHelpFormatter)
	parser.add_argument('path', type=str, help='Path to the data file.')
	parser.add_argument('-x', '--x_label', type=str, help='Label of the x-axis plot.', default='X')
	parser.add_argument('-y', '--y_label', type=str, help='Label of the y-axis plot.', default='Y')
	parser.add_argument('-p', '--plot', action='store_true', help='Plot the data and the regression line.', default=False)
	parser.add_argument('-o', '--output', type=str, help='Path to the output file.', default='output.txt')
	parser.add_argument('-th', '--mse_threshold', type=float, help='Mean Squared Error threshold.', default=0.00000001)
	parser.add_argument('-it', '--max_iterations', type=int, help='Maximum number of iterations.', default=100000)
	parser.add_argument('-lr', '--learning_rate', type=float, help='Learning rate of the model.', default=0.05)

	args = parser.parse_args()

	t = Train(args.path, args.x_label, args.y_label, args.plot, args.output, args.mse_threshold, args.max_iterations, args.learning_rate)

if __name__ == "__main__":
	main()

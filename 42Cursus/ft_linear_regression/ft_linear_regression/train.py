import matplotlib.pyplot as plt


def load_data(path: str) -> tuple[tuple[int, int]]: # TODO dico
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

def normalize_data(data: tuple[tuple[int, int]]) -> tuple[tuple[int, int]]:
	minimum_x = min(data, key=lambda x: x[0])[0]
	maximum_x = max(data, key=lambda x: x[0])[0]
	minimum_y = min(data, key=lambda x: x[1])[1]
	maximum_y = max(data, key=lambda x: x[1])[1]
	return tuple(((x - minimum_x) / (maximum_x - minimum_x), (y - minimum_y) / (maximum_y - minimum_y)) for x, y in data)


theta0, theta1 = 0,0
def gradient_descent(data):
	global theta0, theta1
	learning_rate = 0.05
	m = len(data)
	tmpTheta0 = learning_rate * 1/m * sum(estimate_price(data[i][0], theta0, theta1) - data[i][1] for i in range(m))
	tmpTheta1 = learning_rate * 1/m * sum((estimate_price(data[i][0], theta0, theta1) - data[i][1])* data[i][0] for i in range(m))
	theta0 -= tmpTheta0
	theta1 -= tmpTheta1

def estimate_price(mileage, theta0, theta1):
	return theta0 + (theta1 * mileage)

def plot(data):
	plt.plot(*zip(*data), 'ro')

	x = [i/100 for i in range(0, 100, 1)]
	y = [estimate_price(i, theta0, theta1) for i in x]
	plt.plot(x, y)
	plt.show()

data = load_data("data.csv")
data = normalize_data(data)
for i in range(10000):
	gradient_descent(data)
	# if i % 10 == 0:
plot(data)
print(theta0, theta1)

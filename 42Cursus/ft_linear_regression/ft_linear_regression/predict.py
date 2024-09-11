from typing import Tuple

def get_thetas(file_path: str) -> Tuple[float, float]:
	try:
		with open(file_path, 'r') as file:
			try:
				theta_intercept, theta_slope = map(float, file.read().split(','))
				return theta_intercept, theta_slope
			except ValueError:
				print("The file must contain two float values separated by a comma.")
				exit(1)
	except FileNotFoundError:
		print(f"File '{file_path}' not found.")
		exit(1)
	except Exception as e:
		print(f"An error occurred while reading the file: {e}")
		exit(1)

def predict(theta_intercept: float, theta_slope: float, x: float) -> float:
	return theta_intercept + theta_slope * x

def main():
	import argparse
	parser = argparse.ArgumentParser(description="Prediction based on a linear regression model.")
	parser.add_argument('-f', '--file', type=str, help='Path to the file containing the Thetas values (separated by a comma).', default='output.txt')
	args = parser.parse_args()

	theta_intercept, theta_slope = get_thetas(args.file)
	print("Press 'q' to quit.")
	while True:
		x = input("Enter a value for x: ")
		if x == 'q':
			break
		try:
			x = float(x)
			print(f"Prediction: {predict(theta_intercept, theta_slope, x)}")
		except ValueError:
			print("The value must be a number.")

if __name__ == "__main__":
	main()

import sys
from equationSolver import EquationSolver
from equationParser import EquationParser

def main() -> None:
	if len(sys.argv) != 2:
		print("Usage: python3 main.py \"equation\"")
		sys.exit(1)
	equationStr : str = sys.argv[1]
	# Parse the equation
	try:
		equation: EquationParser = EquationParser(equationStr)
	except Exception as e:
		print("Error while parsing :", e)
		return
	# Solve the equation
	# Print the solution
	print("Reduced form:", str(equation))
	print("Polynomial degree:", equation.getDegree())
	try:
		solutions = EquationSolver(equation).getSolutions()
		if solutions is True: # special case (0=0)
			print("Each real number is a solution...")
		else:
			print("The solution is:" if len(solutions) == 1 else "The solutions are:")
			print(*solutions)
	except Exception as e:
		print(e)





if __name__ == "__main__":
	main()

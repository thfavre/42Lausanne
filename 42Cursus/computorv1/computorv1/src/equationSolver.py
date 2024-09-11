from equationParser import EquationParser
from math import sqrt


class EquationSolver:
	def __init__(self, equation: EquationParser) -> None:
		self._solutions = EquationSolver._solve(equation)

	@staticmethod
	def _solve(equation: EquationParser) -> tuple:
		a: float = equation.getTerm(2)
		b: float = equation.getTerm(1)
		c: float = equation.getTerm(0)
		if equation.getDegree() == 2:
			return EquationSolver._solveSecondDegree(a, b, c)
		elif equation.getDegree() == 1:
			return EquationSolver._solveFirstDegree(b, c)
		elif equation.getDegree() == 0:
			if c == 0:
				return True
			else:
				raise Exception(f"The equation is wrong.. ({c} =! 0)")
		else:
			raise Exception("The polynomial degree is strictly greater than 2, I can't solve.")


	@staticmethod
	def _solveSecondDegree(a: int, b: int, c: int) -> tuple:
		discriminant: float = EquationSolver._calculateDiscriminant(a, b, c)
		if discriminant < 0:
			return (f"{-b/(2*a)} - {sqrt(-discriminant)/(2*a)}i", f"{-b/(2*a)} + {sqrt(-discriminant)/(2*a)}i")
			# return None
		elif discriminant == 0:
			print("Discriminant == 0, one solution")
			return (-b/(2*a), )
		else:
			print("Discriminant > 0, two solutions")
			return tuple(sorted(((-b - sqrt(discriminant))/(2*a), (-b + sqrt(discriminant))/(2*a))))

	@staticmethod
	def _calculateDiscriminant(a: int, b: int, c: int) -> float:
		return b*b - 4*a*c

	@staticmethod
	def _solveFirstDegree(b: int, c: int) -> tuple:
		return (-c/b, )

	def getSolutions(self):
		return self._solutions

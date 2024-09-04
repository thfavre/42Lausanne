

class EquationParser:
	def __init__(self, equation: str) -> None:
		# TODO ! verify the equation is correctly formated
		leftAndRightEquation = equation.split('=')
		if len(leftAndRightEquation) != 2:
			raise Exception("There should be exactly one '='...")
		leftHandSide, rightHandSide = leftAndRightEquation
		leftTerms = EquationParser._createTerms(leftHandSide)
		rightTerms = EquationParser._createTerms(rightHandSide)
		self._equation = EquationParser._ReduceForm(leftTerms, rightTerms)

	@staticmethod
	def _createTerms(polynom: str) -> dict[int]:
		terms = {}
		polynom = polynom.replace(' ', '')
		polynom = polynom.replace('-', '+-')
		termsList : list[str] = polynom.split('+')
		for term in termsList:
			if not term:
				continue
			if len(term.split('*')) == 1:
				if '^' in term: # (ex: X^2)
					degree=term.split('^')[1]
					coefficient = -1 if '-' in term else 1
				elif 'X' in term: # (ex: -X)
					degree = 1
					print("term", term)
					coefficient = -1 if '-' in term else 1
				else: # (ex: 4)
					degree=0
					coefficient=term
				EquationParser._addTerm(terms, int(degree), float(coefficient))
				continue
			coefficient, degree = term.split('*')
			if '^' not in degree:
				degree = 1
			else:
				_, degree = degree.split('^')
			EquationParser._addTerm(terms, int(degree), float(coefficient))
		return terms

	@staticmethod
	def _addTerm(terms: dict[int], degree: int, coefficient: float) -> None:
		if degree not in terms:
			terms[degree] = coefficient
		else:
			terms[degree] += coefficient

	@staticmethod
	def _ReduceForm(leftTerms: dict[int], rightTerms: dict[int]) -> dict[int]: # will put all terms from the right to the left
		reducedTerms = leftTerms.copy()
		for degree, coefficient in rightTerms.items():
			EquationParser._addTerm(reducedTerms, degree, -coefficient)
			if reducedTerms[degree] == 0: # Remove the term if the coefficient is 0
				del reducedTerms[degree]
		return reducedTerms

	def getTerm(self, degree: int):
		if degree in self._equation:
			return self._equation[degree]
		return 0

	# @staticmethod
	# def getTermFromDict(equation: dict[int], degree: int):
	# 	if degree in equation:
	# 		return equation[degree]
	# 	return 0

	def getEquation(self):
		return self._equation

	def getDegree(self):
		if not self._equation:
			return 0
		return max(self._equation)

	def __str__(self):
		return " + ".join([str(coeff) + (f"X"+(f"^{degree}" if degree != 1 else "") if degree != 0 else "") \
			for degree, coeff in sorted(self._equation.items(), reverse=True)]) + " = 0"


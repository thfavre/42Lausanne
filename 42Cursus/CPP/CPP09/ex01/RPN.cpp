#include "RPN.hpp"

#include "RPN.hpp"
#include <sstream>

RPN::RPN(std::string param)
{
	_error = 0;
	evaluateExpression(param);
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src) {
		this->_stack = src.getStack();
		this->_error = src.getError();
	}
	return *this;
}

std::stack<long> RPN::getStack(void) const {
	return _stack;
}

int RPN::getError(void) const {
	return _error;
}

void RPN::setError() {
	_error = 1;
}

void RPN::evaluateExpression(std::string param)
{
	std::istringstream iss(param);
	std::string token;
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (!performOperation(token))
			{
				setError();
				return;
			}
		}

		else
		{
			bool validOperand = true;
			for (size_t i = 0; i < token.size(); ++i) {
				if (!isdigit(token[i])) {
					validOperand = false;
					break;
				}
			}

			if (validOperand) {
				int num = atoi(token.c_str());
				if (num >= 10) {
					std::cerr << "\033[1;31mError : Operand must be a single digit less than 10" << std::endl;
					setError();
					return;
				}
				pushOperand(token);
			}
			else
			{
				std::cerr << "\033[1;31mError : Invalid operand" << std::endl;
				setError();
				return;
			}
		}
	}
}


bool RPN::performOperation(std::string token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/") {
		if (_stack.size() < 2) {
			std::cerr << "\033[1;31mError : Insufficient/Too much operands " << std::endl;
			setError();
			return false;
		}
		long operand2 = _stack.top();
		_stack.pop();
		long operand1 = _stack.top();
		_stack.pop();
		long result;
		if (token == "+")
			result = operand1 + operand2;
		else if (token == "-")
			result = operand1 - operand2;
		else if (token == "*")
			result = operand1 * operand2;
		else if (token == "/") {
			if (operand2 == 0)
			{
				std::cerr << "\033[1;31mError : Division by zero" << std::endl;
				setError();
				return false;
			}
			result = operand1 / operand2;
		}
		_stack.push(result);
		return true;
	}
	std::cerr << "\033[1;31mError : Problem encountered with this operation " << std::endl;
	return false;
}

void RPN::pushOperand(std::string token) {
	long num = std::stol(token);
	_stack.push(num);
}

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	public :
		RPN(std::string param);
		RPN(RPN const &src);
		~RPN(void);
		RPN	&operator=(RPN const &src);

		std::stack<long>	getStack(void) const;
		int getError(void) const;
		void setError();

	private :
		void evaluateExpression(std::string param);
		bool performOperation(std::string token);
		void pushOperand(std::string token);

		std::stack<long> _stack;
		int _error;
};

#endif

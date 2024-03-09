#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() {}

		MutantStack<T>(const MutantStack &mutantStack)
		{
			*this=mutantStack;
		}

		~MutantStack<T>() {}

		MutantStack<T>	&operator=(const MutantStack<T> &ms)
		{
			*this = ms;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}
};



#endif // MUTANT_STACK_HPP

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &mutantStack)
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void);
		iterator	end(void);


};



#endif // MUTANT_STACK_HPP

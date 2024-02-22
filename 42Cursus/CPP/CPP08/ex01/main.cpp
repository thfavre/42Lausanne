
#include "span.hpp"

int main(void)
{
	Span littleSpan(3);
	try {
		littleSpan.addNumber(1);
		littleSpan.addNumber(4);
		littleSpan.addNumber(6);
		littleSpan.addNumber(121211);
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	littleSpan.display();

	int size = 10000;
	Span megaSpan(size);
	for (int i=0; i<size; i++)
		megaSpan.addNumber(i);
	// megaSpan.display();
	std::cout << "shortestSpan in little :" << littleSpan.shortestSpan() << std::endl;
	std::cout << "shortestSpan in mega :" << megaSpan.shortestSpan() << std::endl;
	std::cout << "longestSpan in little :"<< littleSpan.longestSpan() << std::endl;
	std::cout << "longestSpan in mega :"<< megaSpan.longestSpan() << std::endl;

	std::cout <<std::endl << "---subject example--" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

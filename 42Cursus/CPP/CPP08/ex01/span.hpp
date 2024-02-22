#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span();
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void addNumber(int nb);
		void display();
		int shortestSpan();
		int longestSpan();

		class NoSpaceLeftException : public  std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return "No space left in span";
			}
		};

		class SpanTooSmallException : public  std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return "There is not enough number in the span";
			}
		};

	private:
		unsigned int _size;
		std::vector<int> _elements;

};

#endif // SPAN_HPP

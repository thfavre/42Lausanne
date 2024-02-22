#include "span.hpp"
# include <iostream>
#include <algorithm>
#include <stdlib.h>

Span::Span(void)
{
	_size = 0;
	_elements.reserve(0);
}

Span::Span(unsigned int n)
{
	_size = n;
	_elements.reserve(n);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	this->_size = other._size;
	this->_elements = other._elements;
	return *this;
}

void Span::addNumber(int nb)
{
	if (_elements.size() < _size)
		_elements.push_back(nb);
	else
		throw NoSpaceLeftException();
}

void Span::display()
{
	std::cout << "Span capacity : " << _size << ", current size : " << _elements.size() << std::endl;
	for (unsigned int i=0; i<_elements.size(); i++)
	{
		std::cout << _elements[i] << ", ";
	}
	std::cout << std::endl;

}

int Span::longestSpan()
{
	if (_elements.size() < 2)
		throw (SpanTooSmallException());
	int min = *std::min_element(_elements.begin(), _elements.end());
	int max = *std::max_element(_elements.begin(), _elements.end());
	return max - min;

}

int Span::shortestSpan()
{
	if (_elements.size() < 2)
		throw (SpanTooSmallException());
	int shortest = INT_MAX;
	for (unsigned int i=0; i<_elements.size(); i++)
	{
		for (unsigned int j=i+1; j<_elements.size(); j++)
		{
			int span = abs(_elements[i] - _elements[j]);
			if (span < shortest)
				shortest = span;
		}
	}
	return shortest;
}

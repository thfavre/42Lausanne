#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array<T> &array);

	Array<T>	&operator=(const Array<T> &array);
	T			&operator[](int i) const;

	unsigned int size() const;

	class IndexOutOfBoundsException : public std::exception {
		virtual const char *what(void) const throw()
		{
			return ("Index out of bounds");
		}
	};


private:
	unsigned int _size;
	T *_arr;

} ;


#endif

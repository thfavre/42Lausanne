#ifndef MAX_HPP
# define MAX_HPP

// class do the same as typename
template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

#endif

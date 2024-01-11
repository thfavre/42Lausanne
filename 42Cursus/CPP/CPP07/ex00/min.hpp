#ifndef MIN_HPP
# define MIN_HPP

// class do the same as typename
template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

#endif

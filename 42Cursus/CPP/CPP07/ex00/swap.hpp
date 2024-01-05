#ifndef SWAP_HPP
# define SWAP_HPP

// typename do the same as class
template <typename T>
void swap(T &val1, T &val2)
{
	T save_val2 = val2;
	val2 = val1;
	val1 = save_val2;
}

#endif //SWAP_HPP

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *arr, int lenght, void (&func)(T&))
{
	for (int i=0; i<lenght; i++)
		func(arr[i]);
}

#endif  // ITER_HPP

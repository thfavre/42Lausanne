#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

// #include <cstdint>
#include "Data.hpp"

class Serializer
{

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
};

#endif

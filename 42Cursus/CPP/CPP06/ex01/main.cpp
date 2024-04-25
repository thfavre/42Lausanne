#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

// struct  myStruct
// {
// 	int		x;
// 	int		y;
// 	char	c;
// 	bool	b;
// };

int main() {
	// myStruct s;
	// s.x = 5;
	// s.y = 10;
	// s.c = 'a';
	// s.b = true;
	// int *p = reinterpret_cast<int*>(&s); // we will interpret s as an int pointer
	// std::cout << *p << std::endl; // 5
	// p++; // it is an int pointer, so it will increment by 4 bytes
	// std::cout << *p << std::endl; // 10
	// p++;
	// std::cout << *p << std::endl; // ???
	// // char *c = reinterpret_cast<char*>(p); // we will interpret p as a char pointer (1 byte)
	// // std::cout << *c << std::endl; // a

	Data data;
	data.n = 42;
	data.s1 = "Hello";
	data.s2 = "World";
	std::cout << "Data: " << &data << std::endl;
	std::cout << "n: " << data.n << std::endl;
	std::cout << "s1: " << data.s1 << std::endl;
	std::cout << "s2: " << data.s2 << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized << std::endl;
	std::cout << "n: " << deserialized->n << std::endl;
	std::cout << "s1: " << deserialized->s1 << std::endl;
	std::cout << "s2: " << deserialized->s2 << std::endl;





}

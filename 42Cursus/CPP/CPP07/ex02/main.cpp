#include <iostream>
#include <string>
#include "Array.tpp"




int main()
{
	Array <int>array1(3);
	array1[1] = 13;
	Array <std::string>arrayString(1);
	arrayString[0] = "blaaaa";
	Array <int>array2(array1);
	// print the size
	std::cout << "The size of the array1 is : " << array1.size() << std::endl;
	std::cout << "The size of the array2 is : " << array2.size() << std::endl;

	std::cout << "first element of array1: "<<array1[0] << std::endl;
	std::cout << "filling the array1" << std::endl;
	array1[0] = 3;
	std::cout << "first element of array1: "<<array1[0] << std::endl;
	std::cout << "second element of array2: "<<array2[1] << std::endl;
	std::cout << "first element of arrayString: "<<arrayString[0] << std::endl;

	std::cout << std::endl << "Try index too big" << std::endl;
	try{
		array1[44] = 8;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}






}

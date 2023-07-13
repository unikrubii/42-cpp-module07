#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	std::cout << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << "||   My own Test   ||" << std::endl;
	std::cout << "=====================" << std::endl;

	std::cout << "instantiate Array<std::string> str(3)" << std::endl;
	Array<std::string> str(3);
	std::string *s = new std::string[3];
	for (int i = 0; i < 3; i++)
	{
		str[i] = "This is string # " + std::to_string(i);
		s[i] = "This is string # " + std::to_string(i);;
	}
	std::cout << "====================" << std::endl;
	{
		Array<std::string> tmp = str;
		std::cout << "tmp = str, tmp addr: " << &tmp << " str addr: " << &str << std::endl;
		Array<std::string> test(tmp);
		std::cout << "test(tmp), test addr: " << &test << " tmp addr: " << &tmp << std::endl;
		std::cout << "====================" << std::endl;
		std::cout << "check if tmp and test have same value" << std::endl;
		for (int i = 0; i < 3; i++) {
			if (tmp[i] != test[i]) {
				std::cerr << "No, didn't save the same value!!" << std::endl;
				return 1;
			}
			else {
				std::cout << "Yes, value: " << test[i] << std::endl;
			}
		}
		std::cout << "====================" << std::endl;
		std::cout << "change value in test" << std::endl;
		test[1] = "This is string # 1 changed";
		std::cout << "test[1]: " << test[1] << std::endl;
		std::cout << "tmp[1]: " << tmp[1] << std::endl;
	}
	std::cout << "====================" << std::endl;
	{
		std::cout << "trying access index of 3" << std::endl;
		try {
			str[3] = "This is string # 3";
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "====================" << std::endl;
	{
		std::cout << "trying access index of negative (-2)" << std::endl;
		try {
			str[-2] = "This is string # 3";
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	delete [] s;

	return 0;
}
#include "ScalarConverter.hpp"

int main(int ac, char **av){
	if (ac != 2)
		std::cout << "Wrong number of arguments" << std::endl;
	else
		ScalaConverter::convert(av[1]);
	return (0);
}
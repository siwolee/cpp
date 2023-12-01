#include <string.h>
#include "ScalarConverter.hpp"
#include <sstream>

//stof, stod -> c++ 11
void	ft_stoi(std::string str){
	int 		i;
	std::string	res;
	std::stringstream	ss(str);
	try {
		ss >> i;
	}
	catch (std::exception & e){
		std::cout << "int    : impossible" << std::endl;
	}
	std::cout << "int    : " << i << std::endl;
}




void ScalaConverter::convert(std::string str){
	char c;
	long int i;
	float f;
	double d;
	// std::istringstream iss(str + " " + str + " " + str + " " + str);

	//display char 
	//- if not displayable, display "Non displayable"
	//- if not a char, display "impossible"
	try {
		i = strtol(str);
		c = static_cast<char>(i);
	}
	catch (std::exception & e){
		std::cout << "char   : impossible" << std::endl;
	}
	std::cout << "char   : " << c << std::endl;

	//display int
	//if it's behind int range, display "impossible"
	// try {
	// 	iss >> i;
	// 	std::cout << "int    : " << i << std::endl;
	// }
	// catch (std::exception & e){
	// 	std::cout << "int    : impossible" << std::endl;
	// }

	
	// //display float
	// //-inff, +inff, nanf
	// try {
	// 	iss >> f;
	// 	std::cout << "float  : " << i << "f" << std::endl; 
	// }
	// catch (std::exception & e){
	// 	std::cout << "float  : impossible" << std::endl;
	// }

	// //display double
	// //-inf, +inf, nan
	// 	iss >> d;
	// try {
	// 	std::cout << "double : " << d << std::endl;
	// }
	// catch (std::exception & e){
	// 	std::cout << "double : impossible" << std::endl;
	// }
}

ScalaConverter::ScalaConverter(){}

ScalaConverter::~ScalaConverter(){}

ScalaConverter::ScalaConverter(ScalaConverter & copy){
	*this = copy;
}

ScalaConverter & ScalaConverter::operator=(ScalaConverter & assign){
	if (this == &assign)
		return (*this);
	return (*this);
}

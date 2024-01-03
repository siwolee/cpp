#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "ScalarConverter.hpp"


void ScalaConverter::convert(std::string str){
	int	const			CMDCNT = 6;
	double base;

	std::string inf[CMDCNT] = {"inf", "+inf", "-inf", "inff", "-inff", "+inff"};
	std::string nan[CMDCNT] = {"nan", "+nan", "-nan", "nanf", "-nanf", "+nanf"};

	for (int i = 0; i < CMDCNT ; i++){
		if (inf[i] == str){
			std::cout << "char   : impossible" << std::endl;
			std::cout << "int    : impossible" << std::endl;
			std::cout << "float  : inff" << std::endl;
			std::cout << "double : inf" << std::endl;
			return ;
		}
		else if (nan[i] == str){
			std::cout << "char   : impossible" << std::endl;
			std::cout << "int    : impossible" << std::endl;
			std::cout << "float  : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
			return ;
		}
	}
	
	if (str[str.size() - 1] == 'f')
		str.erase(str.end() - 1);
	
	std::stringstream	ss(str);
	ss >> base;
	if (ss.fail()){
		std::cout << "char   : impossible" << std::endl;
		std::cout << "int    : impossible" << std::endl;
		std::cout << "float  : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return ;
	}
	
	//char
	if (base < -128 || base > 127){
		std::cout << "char   : impossible" << std::endl;
		// std::cout << "char   : '" << static_cast<char>(base) << "'" << std::endl;
	}
	else if (base > 126 || base < 33){
		std::cout << "char   : Non displayable" << std::endl;
		// std::cout << "char   : '" << static_cast<char>(base) << "'" << std::endl;
	}
	else {
		std::cout << "char   : '" << static_cast<char>(base) << "'" << std::endl;
	}

	//int
	if (base > 2147483647 || base < -2147483648){
		std::cout << "int    : impossible" << std::endl;
		// std::cout << "int    : " << static_cast<int>(base) << std::endl;
	}
	else 
		std::cout << "int    : " << static_cast<int>(base) << std::endl;
		
	std::cout << "float  : " << std::fixed << std::setprecision(1) << static_cast<float>(base) << "f"<< std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(base) << std::endl;
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

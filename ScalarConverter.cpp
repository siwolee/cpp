#include <string>
#include <sstream>
#include <iomanip>
#include "ScalarConverter.hpp"

//stof, stod -> c++ 11

//display int
//if it's behind int range, display "impossible"
void	ft_stoi(std::string & str){
	int					i;
	std::stringstream	ss(str);
	ss >> i;
	if (ss.fail()){ 
		std::cout << "int    : impossible" << std::endl;
	}
	else {
		std::cout << "int    : " << i << std::endl;
	}
}


//display char 
//- if not displayable, display "Non displayable"
//- if not a char, display "impossible"
void ft_stoc(std::string & str){
	int					c;
	std::stringstream	ss(str);
	ss >> c;
	if (ss.fail() || c < -128 || c > 127){
		std::cout << "char   : impossible" << std::endl;
	}
	else if (c > 126 || c < 33){
		std::cout << "char   : Non displayable" << std::endl;
	}
	else {
		std::cout << "char   : '" << static_cast<char>(c) << "'" << std::endl;
	}
}

//display float
//-inff, +inff, nanf
void	ft_stof(std::string & str){
	float				f;
	std::stringstream	ss(str);
	ss >> f;
	if (ss.fail()){
		std::cout << "float  : impossible" << std::endl;
	}
	else {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float  : " << f << "f" << std::endl; 
	}

}

// display double
// -inf, +inf, nan
void	ft_stod(std::string & str){
	double				d;
	std::stringstream	ss(str);
	ss >> d;
	if (ss.fail()){
		std::cout << "double : impossible" << std::endl;
	}
	else {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double : " << d << std::endl;
	}
}


void ScalaConverter::convert(std::string str){
	std::stringstream	ss(str);
	int	const			CMDCNT = 6;

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
	// ft_stoc(str);
	// ft_stoi(str);
	// ft_stof(str);
	// ft_stod(str);

	long long base;
	ss >> base;
	if (ss.fail()){
		std::cout << "char   : impossible" << std::endl;
		std::cout << "int    : impossible" << std::endl;
		std::cout << "float  : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(base);
	float f = static_cast<float>(base);
	double d = static_cast<double>(base);

	if (static_cast<int>(base))
		std::cout << "ok" << std::endl;
	if (f - roundf(f) || i < -128 || i > 127){
		std::cout << "char   : impossible" << std::endl;
	}
	else if (i > 126 || i < 33){
		std::cout << "char   : Non displayable" << std::endl;
	}
	else {
		std::cout << "char   : '" << i << "'" << std::endl;
	}
	std::cout << "int    : " << i << std::endl;
	std::cout << "float  : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << d << std::endl;

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

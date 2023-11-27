#include "Bureaucrat.hpp"

int main(){
	Bureaucrat a = Bureaucrat("John");
	std::cout << a << std::endl;

	a.decreaseGrade();
	a.decreaseGrade();

	std::cout << a << std::endl;
	a. increaseGrade();
	std::cout << a << std::endl;
	
	Bureaucrat b = Bureaucrat("King author", 1);
	std::cout << b << std::endl;
	b.increaseGrade();
	b.increaseGrade();
	std::cout << b << std::endl;
	b.decreaseGrade();
	std::cout << b << std::endl;

	Bureaucrat c = Bureaucrat("the god", 0);
	std::cout << c << std::endl;

	Bureaucrat d = Bureaucrat("thing", 200);
	std::cout << d << std::endl;
}
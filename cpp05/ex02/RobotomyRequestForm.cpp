#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm") {
	signGrade = 72;
	execGrade = 45;
	target = "roborobo";
};

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm"){
	target = _target;
	signGrade = 72;
	execGrade = 45;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & assign){
	if (this == &assign)
		return (*this);
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy){
	*this = copy;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > execGrade)
		throw AForm::GradeTooLowException();
	std::cout << "drrrrrrrrrrrrrrrr....."<< std::endl;
	std::cout << "drrrrrrrrrrrrrrrr....."<< std::endl;
	int seed = rand() * rand();
	// std::cout << seed<< std::endl;
	if (seed % 4 > 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " has not!!! been robotomized" << std::endl;
	std::cout << "PresidentialPardonForm has been executed by " << executor.getName() << std::endl;
}

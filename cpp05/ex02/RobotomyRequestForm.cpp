#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 75, 45) {
	target = "roborobo";
};

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 75, 45){
	target = _target;
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
	std::cout << BOLDYELLOW << std::setw(20) << std::left << "RobotomyRequest" << RESET << "|";
	std::cout << BOLDYELLOW  << std::setw(10) << std::left << executor.getName() << RESET << "|";
	std::cout << BOLDYELLOW  << std::setw(10) << std::left << target << RESET << "|";
	try {
		if (executor.getGrade() > execGrade)
			throw AForm::GradeTooLowException();
		std::cout << BOLDGREEN << std::setw(12) << std::left << "sucess✅" << RESET << "|";
		int seed = rand() % 2;
		if (seed == 1)
			std::cout << BOLDGREEN << std::setw(50) << std::left << "robotomised " + target + RESET + "(drilling noise)" << std::endl;
		else
			std::cout << BOLDRED << std::setw(50) << std::left << "not robotomised" + target + RESET + "(drilling noise)" << std::endl;
	}
	catch (std::exception &e){
		std::cout << BOLDRED << std::setw(13) << std::left << "fail🚫" << RESET << "|";
		std::cout << std::setw(50) << std::left << std::setfill('.') << RESET << std::endl << std::setfill(' ');
	}
}

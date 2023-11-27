#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm") {
	signGrade = 25;
	execGrade = 5;
	target = "president";
};

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm"){
	target = _target;
	signGrade = 25;
	execGrade = 5;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & assign){
	if (this == &assign)
		return (*this);
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy){
	*this = copy;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (executor.getGrade() > execGrade)
		throw AForm::GradeTooLowException();
	std::cout << "Information :: "<< target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << "RobotomyRequestForm has been executed by " << executor.getName() << std::endl;
}



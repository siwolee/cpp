#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
	target = "president";
};

PresidentialPardonForm::~PresidentialPardonForm(){};

PresidentialPardonForm::PresidentialPardonForm(std::string _target): AForm("PresidentialPardonForm", 25, 5){
	target = _target;
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
	std::cout << BOLDYELLOW << std::setw(20) << std::left << "PresidentialPardon" << RESET << "|";
	std::cout << BOLDYELLOW  << std::setw(10) << std::left << executor.getName() << RESET << "|";
	std::cout << BOLDYELLOW  << std::setw(10) << std::left << target << RESET << "|";
	try {
		if (executor.getGrade() > execGrade)
			throw AForm::GradeTooLowException();
		std::cout << BOLDGREEN << std::setw(12) << std::left << "sucess✅" << RESET << "|";
		std::cout << target << std::setw(50) << std::left << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
	}
	catch (std::exception &e){
		std::cout << BOLDRED << std::setw(13) << std::left << "fail🚫" << RESET << "|";
		std::cout << std::setw(50) << std::left << std::setfill('.') << RESET << std::endl << std::setfill(' ');
	}

}



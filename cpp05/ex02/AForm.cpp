#include "AForm.hpp"

AForm::AForm(): name("default"),  isSigned(false), signGrade(150), execGrade(150), target(""){};

AForm::AForm(std::string _name): name(_name),  isSigned(false), signGrade(150), execGrade(150), target(""){};

AForm::AForm(std::string _name, int _signGrade, int _execGrade): name(_name), signGrade(_signGrade), execGrade(_execGrade){
	try {
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception & e) {
		std::cout << BOLDRED << name << " exception: " << e.what() << ", will be initialised to available value" << RESET << std::endl;
		signGrade = (signGrade > 150 ? 150 : signGrade);
		signGrade = (signGrade < 1 ? 1 : signGrade);
		execGrade = (execGrade > 150 ? 150 : execGrade);
		execGrade = (execGrade < 1 ? 1 : execGrade);
	}
}

AForm::~AForm(){};

std::string	AForm::getName() const { return (name);}
int			AForm::getSignGrade() const{ return (signGrade);}
int			AForm::getExecGrade() const{ return (execGrade);}
bool		AForm::getIsSigned() const{ return (isSigned);}

void		AForm::beSigned(const Bureaucrat & b){
	if (b.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char * AForm::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
};

std::ostream & operator<<(std::ostream & out, const AForm & self){
	out << "AForm " << self.getName() << " is " << (self.getIsSigned() ? "signed" : "not signed") << std::endl;
	return out;
}
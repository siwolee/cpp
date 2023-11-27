#include "AForm.hpp"

AForm::AForm(): name("default"),  isSigned(false), signGrade(150), execGrade(150), target(""){};

AForm::AForm(std::string _name): name(_name),  isSigned(false), signGrade(150), execGrade(150), target(""){};


AForm::~AForm(){};

// AForm & AForm::operator=(const AForm & assign){
// 	if (this == &assign){
// 		signGrade = assign.signGrade;
// 		execGrade = assign.execGrade;
// 		isSigned = assign.isSigned;
// 	}
// 	return (*this);
// }

// AForm::AForm(const AForm & copy){
// 	*this = copy;
// }

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
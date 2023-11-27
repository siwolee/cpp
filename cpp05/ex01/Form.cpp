#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), signGrade(150), execGrade(150){};

Form::~Form(){};

Form::Form(std::string _name): name(_name), isSigned(false), signGrade(150), execGrade(150){};

Form & Form::operator=(const Form & assign){
	if (this == &assign)
		return (*this);
	return (*this);
}

Form::Form(const Form & copy){
	*this = copy;
}

std::string	Form::getName() const { return (name);}

int			Form::getSignGrade() const{ return (signGrade);}
int			Form::getExecGrade() const{ return (execGrade);}
bool		Form::getIsSigned() const{ return (isSigned);}

void		Form::beSigned(const Bureaucrat & b){
	if (b.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
}

const char * Form::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
};

std::ostream & operator<<(std::ostream & out, const Form & self){
	out << "Form " << self.getName() << " is " << (self.getIsSigned() ? "signed" : "not signed") << std::endl;
	return out;
}



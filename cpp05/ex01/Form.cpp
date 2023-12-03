#include "Form.hpp"

Form::Form(): name("default"), isSigned(false), signGrade(150), execGrade(150){};

Form::~Form(){};

Form::Form(std::string _name): name(_name), isSigned(false), signGrade(150), execGrade(150){};

Form::Form(std::string _name, int _signGrade, int _execGrade): name(_name), signGrade(_signGrade), execGrade(_execGrade){
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

Form & Form::operator=(const Form & assign){
	if (this == &assign)
		return (*this);
	return (*this);
}

Form::Form(const Form & copy): signGrade(copy.signGrade), execGrade(copy.execGrade){
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



#include "Bureaucrat.hpp"

void 	Bureaucrat::executeForm(const AForm & form){
	try{
		form.execute(*this);
	}
	catch (AForm::GradeTooLowException & e) {
		std::cout << name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm *form){
	if (form->getIsSigned() == true){
		std::cerr << name << " couldn't sign " << form->getName() << " because it is already signed" << std::endl;
		return ;
	}
	try	{
		form->beSigned(*this);
	}
	catch (AForm::GradeTooLowException & e) {
		std::cout << name << " cannot sign " << form->getName() << " because his grade is too low" << std::endl;
		return ;
	}
	std::cout << name << " signs " << form->getName() << std::endl;
}

void	Bureaucrat::increaseGrade(){
	try {
		grade--;
		if (grade < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException & e) {
		std::cout << name << " error: " << e.what()<< std::endl;
		grade = 1;
	}
}

void	Bureaucrat::decreaseGrade(){
	try {
		grade++;
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooLowException & e) {
		std::cout << name << " error: " << e.what()<< std::endl;
		grade = 150;
	}

};


const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low");
};
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high");
};

Bureaucrat::Bureaucrat(): name("default"), grade(150){}

Bureaucrat::Bureaucrat(std::string _name): name(_name), grade(150) {}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name) {
	try {
		grade = _grade;
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException & e) {
		std::cout << name << " error: " << e.what()<< std::endl;
		grade = 1;
	}
	catch (GradeTooLowException & e) {
		std::cout << name << " error: " << e.what()<< std::endl;
		grade = 150;
	}
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & assign){
	grade = assign.grade;
	return (*this);
}


Bureaucrat::Bureaucrat(const Bureaucrat & copy): name(copy.name), grade(copy.grade){}

std::string			Bureaucrat::getName() const { return (name);}

int					Bureaucrat::getGrade() const { return (grade);}

std::ostream & operator<<(std::ostream & out, const Bureaucrat & self){
	out << self.getName() << ", bureaucrat grade " << self.getGrade() ;
	return (out);
}
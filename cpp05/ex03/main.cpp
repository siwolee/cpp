#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	srand(static_cast<unsigned int>(time(0)));
	Bureaucrat	a = Bureaucrat("Low");
	Bureaucrat	b = Bureaucrat("Mid", 140);
	Bureaucrat	c = Bureaucrat("high", 50);
	Bureaucrat	d = Bureaucrat("king", 6);
	Bureaucrat	e = Bureaucrat("god", 1);
	Intern newb = Intern();
	AForm *sh = newb.makeForm("shrubbery creation", "new garden"); 
	AForm *ro = newb.makeForm("robotomy request", "new vim");
	AForm *pp = newb.makeForm("presidential pardon", "new cute");
	AForm *error = newb.makeForm("error", "error");

	d.signForm(sh);
	c.signForm(ro);
	d.signForm(pp);

	std::cout << sh << ro << pp;
	delete sh;
	delete ro;
	delete pp;
	delete error;
}
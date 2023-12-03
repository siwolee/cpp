#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main(){
	srand(static_cast<unsigned int>(time(0)));
	Bureaucrat	a = Bureaucrat("high", 1);
	Bureaucrat	b = Bureaucrat("mid", 75);
	Bureaucrat	c = Bureaucrat("low");

	ShrubberyCreationForm	sh = ShrubberyCreationForm("bash");
	RobotomyRequestForm	ro = RobotomyRequestForm("vim");
	PresidentialPardonForm	pp = PresidentialPardonForm("cute");


	std::cout << "\n" << a << std::endl;
	a.signForm(&sh);
	a.signForm(&ro);
	a.signForm(&pp);

	
	std::cout << "\n" << BOLDWHITE << std::setw(20) << std::left << "Form name" << "|";
	std::cout << std::setw(10) << std::left << "executor" << "|";
	std::cout << std::setw(10) << std::left << "target" << "|";
	std::cout << std::setw(11) << std::left << "result" << "|";
	std::cout << std::setw(50) << std::left << "notes" << std::endl;

	a.executeForm(sh);
	a.executeForm(ro);
	a.executeForm(ro);
	a.executeForm(pp);
	b.executeForm(sh);
	b.executeForm(ro);
	b.executeForm(pp);
	c.executeForm(sh);
	c.executeForm(sh);
	c.executeForm(ro);
	c.executeForm(pp);

	return (0);
}
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
	// srand(static_cast<unsigned int>(time(0)));
	Bureaucrat	a = Bureaucrat("Low");
	Bureaucrat	b = Bureaucrat("Mid", 140);
	Bureaucrat	c = Bureaucrat("high", 50);
	Bureaucrat	d = Bureaucrat("king", 6);
	Bureaucrat	e = Bureaucrat("god", 1);

	ShrubberyCreationForm	sh = ShrubberyCreationForm("bash");
	RobotomyRequestForm	ro = RobotomyRequestForm("vim");
	PresidentialPardonForm	pp = PresidentialPardonForm("cute");


	std::cout << "\n" << a << std::endl;
	a.signForm(&sh);
	a.signForm(&ro);
	a.signForm(&pp);
	std::cout << sh;
	a.executeForm(sh);

	std::cout << "\n" << b << std::endl;
	b.signForm(&sh);
	b.signForm(&ro);
	b.signForm(&pp);

	std::cout << sh;
	std::cout << ro;
	b.executeForm(sh);
	b.executeForm(ro);
	b.executeForm(pp);

	std::cout << "\n" << c << std::endl;
	c.signForm(&sh);
	c.signForm(&ro);
	c.signForm(&pp);
	std::cout << sh << ro << pp;
	c.executeForm(sh);
	c.executeForm(ro);
	c.executeForm(pp);

	std::cout << "\n" << d << std::endl;
	d.executeForm(ro);
	d.signForm(&pp);
	std::cout << pp;
	d.executeForm(pp);

	std::cout << "\n" << e << std::endl;
	e.executeForm(ro);
	e.executeForm(pp);
}
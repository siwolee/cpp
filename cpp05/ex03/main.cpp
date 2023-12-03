#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main(){
	srand(static_cast<unsigned int>(time(0)));
	Bureaucrat	d = Bureaucrat("king", 6);
	Intern newb = Intern();
	AForm *sh = newb.makeForm("Shrubbery Creation", "new garden"); 
	AForm *ro = newb.makeForm("Robotomy Request", "new vim");
	AForm *pp = newb.makeForm( "Preidential Pardon", "new cute");
	AForm *error = newb.makeForm("error", "error");

	d.signForm(sh);
	d.signForm(ro);
	d.signForm(pp);

	std::cout << "\n" << BOLDWHITE << std::setw(20) << std::left << "Form name" << "|";
	std::cout << std::setw(10) << std::left << "executor" << "|";
	std::cout << std::setw(10) << std::left << "target" << "|";
	std::cout << std::setw(11) << std::left << "result" << "|";
	std::cout << std::setw(50) << std::left << "notes" << std::endl;

	d.executeForm(*sh);
	d.executeForm(*ro);
	d.executeForm(*ro);
	d.executeForm(*pp);

	delete sh;
	delete ro;
	delete pp;
	delete error;
}
#include "Intern.hpp"



AForm * Intern::makeForm(std::string _formName, std::string target){
	int	i = 0;
	int const FORM_CNT = 3;
	std::string formNames[3];
	formNames[0] = "Shrubbery Creation"; 
	formNames[1] = "Robotomy Request" ;
	formNames[2] = "Preidential Pardon";
	
	try {
		for (i = 0; i <= FORM_CNT ; i++){
			if (formNames[i] == _formName){
				std::cout << "Intern creates " << _formName << std::endl;
				break;
			}
			if (i >= FORM_CNT)
				throw (FormNotFoundException());
		}
	}
	catch (FormNotFoundException & e){
		std::cout << e.what() << std::endl;
	}
	switch (i)
	{
		case 0: 
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
	}
	return (0);
}

Intern::Intern(){}

Intern::~Intern(){}

Intern & Intern::operator = (const Intern & assign){
	(void)assign;
	return (*this);
}

Intern::Intern (const Intern & copy){
	(void)copy;
}

const char * Intern::FormNotFoundException::what() const throw(){
	return ("\033[31mIntern: \"I can't find this form... sorry...\"\033[0m");
}
